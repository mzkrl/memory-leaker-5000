#include <math.h>
#include <stdio.h>

int jumlanak;
float gajikotor=1000000, tunjangan, persentunjangan=0.2;

int main(){
    printf("jml anak: ");
    scanf("%d", &jumlanak);
    if(jumlanak > 2){
        persentunjangan = 0.3;
    }
    tunjangan = gajikotor * persentunjangan;
    float t=sqrtf(tunjangan);
    printf("tunjangan  = %.2f\nsqrt=%.2f", tunjangan, t);

}