#include <stdio.h>
char nama[50];
char *writeName(){
    printf("nama: ");
    scanf("%49s", nama);
    return nama;
}
float nilai[3];
int avgNilai(){
    for (int i=0; i<3; i++){
        printf("nilai %d: ", i+1);
        scanf("%f", &nilai[i]);
    }
    float avg= (nilai[0]+nilai[1]+nilai[2])/3;
    return avg;
}
int main(){
    writeName();
    float avg=avgNilai();
    printf("rata2 = %f\n", avg);
    if (avg>60){
        printf("lulus");
    } else{
        printf("lmao g lulus");
    }
    return 0;
}