/*
 * entropy.c — controlled randomness with mean reversion and bias
 *
 * A generic [0, 1] value that behaves like a natural random process:
 * near 0.5 it wanders freely, but the further it strays, the harder
 * it gets pulled back toward equilibrium. Use it for anything that
 * needs "organic" fluctuation — temperature, mood, market sentiment,
 * NPC energy, whatever the simulation calls for.
 *
 * bias:
 *   0 -> random steps tend to push the value below 0.5
 *   1 -> neutral, no directional push
 *   2 -> random steps tend to push the value above 0.5
 *
 * Compile:  gcc -o entropy entropy.c
 * Run:      ./entropy
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EQUILIBRIUM   0.5
#define STEP_SIZE     0.05   /* max size of a random step               */
#define REVERSION     1.2    /* pull-back strength (applied to dist^3)  */
#define BIAS_STRENGTH 0.03   /* how strongly bias nudges a step         */

typedef struct {
    double value;   /* current entropy, always kept in 0..1 */
    int    bias;    /* 0, 1, or 2 */
} Entropy;

static double clamp(double v, double lo, double hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

/* random double in [-1, 1] */
static double rand_signed(void) {
    return ((double)rand() / RAND_MAX) * 2.0 - 1.0;
}

void entropy_init(Entropy *e, double start, int bias) {
    e->value = clamp(start, 0.0, 1.0);
    e->bias  = bias;
}

void entropy_step(Entropy *e) {
    /* base random wobble, positive or negative */
    double raw_step = rand_signed() * STEP_SIZE;

    /* bias shifts the average direction of that wobble:
       bias 0 -> negative push, bias 1 -> none, bias 2 -> positive push */
    double bias_push = (e->bias - 1) * BIAS_STRENGTH;

    /* cubic reversion: barely noticeable near 0.5 (so it can wander
       freely there instead of getting clamped to the middle), but
       grows fast the further it strays, so it never gets stuck out
       at the edges either */
    double distance = EQUILIBRIUM - e->value;
    double reversion_push = distance * distance * distance * REVERSION;

    e->value = clamp(e->value + raw_step + bias_push + reversion_push, 0.0, 1.0);
}

int main(void) {
    srand((unsigned)time(NULL));

    Entropy e;
    entropy_init(&e, 0.5, 1); /* start balanced, neutral bias */

    printf("step\tvalue\n");
    for (int i = 0; i < 30; i++) {
        entropy_step(&e);
        printf("%2d\t%.20f\n", i, e.value);
    }

    return 0;
}