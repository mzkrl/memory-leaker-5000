#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void vol(int s) {
    printf("vol: %d\n", (int)pow(s, 3));
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <side>\n", argv[0]);
        return 1;
    }

    int s = atoi(argv[1]);
    vol(s);

    return 0;
}   