#include <stdio.h>
#include <math.h>

int main() {
    int N, i;
    float total = 0, rata, sum_sq_diff = 0, sd;

    // 1. Meminta input jumlah data N
    printf("Masukkan jumlah data (N): ");
    scanf("%d", &N);

    float X[N]; // Deklarasi array sebesar N

    // 2. Input elemen array dan menghitung total
    printf("\nMasukkan %d nilai data:\n", N);
    for (i = 0; i < N; i++) {
        printf("Data X[%d]: ", i);
        scanf("%f", &X[i]);
        total += X[i]; // Menjumlahkan total
    }

    // 3. Menghitung rata-rata
    rata = total / N;

    // 4. Menghitung jumlah kuadrat selisih (Xi - rata)^2
    for (i = 0; i < N; i++) {
        sum_sq_diff += pow(X[i] - rata, 2);
    }

    // Menghitung Deviasi Standar (SD)
    sd = sqrt(sum_sq_diff / N);

    // 5. Menampilkan hasil
    printf("\n=============================\n");
    printf("          HASIL              \n");
    printf("=============================\n");
    printf("Total           = %.2f\n", total);
    printf("Rata-rata       = %.2f\n", rata);
    printf("Deviasi Standar = %.2f\n", sd);

    return 0;
}