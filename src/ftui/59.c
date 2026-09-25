#include <stdio.h>

const double pi = 3.14159265358979323846;
float r;
double luas;
int main(){
    printf("jari2 = ");
    scanf("%f", &r);
    luas = pi * r * r;
    printf("luas lingkaran = %.8lf\n", luas);
}