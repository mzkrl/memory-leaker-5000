#include <stdio.h>
float r, luas, sisi;
double pi=3.141592653;
int c;
float lling(float r){
    return pi*r*r;
}
float lkubus(float s){
    return s*s;
}
int choice(){
    printf("\noperasi apa?\n0. exit\n1. kubus\n2. lingkaran\nchoice: ");
    scanf("%d", &c);
    return c;
}
int main(){
    while(choice()){
        switch(c){
            case 0:
                return 0;
            case 1:
                printf("sisi: ");
                scanf("%f", &sisi);
                printf("luas kubus = %.2f\n", lkubus(sisi));
                break;
            case 2:
                printf("jari-jari: ");
                scanf("%f", &r);
                printf("luas lingkaran = %.2f\n", lling(r));
                break;
            default:
                printf("\nwrong choice, ulang");
                break;
        }
    }
    return printf("done");
}