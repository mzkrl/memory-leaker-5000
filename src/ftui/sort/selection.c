#include <stdio.h>

int main() {
    int arr[20]; //Array yang ingin dicari
    int n;       //Banyaknya array
    int i, j, k, l;

    //Dapatkan banyak elemen dalam array
    while (1) {
        printf("\nMasukkan banyaknya angka yang berada dalam array: ");
        scanf("%d", &n);

        if ((n > 0) && (n <= 20)) {
            break;
        } else {
            printf("Banyak array minimal harus 1 dan maksimum 20 elemen");
        }
    }

    //Masukkan elemen-elemen dalam array
    printf("\n-----------------------\n");
    printf(" Masukkan Elemen Array \n");
    printf("\n-----------------------\n");

    for (i = 0; i < n; i++) {
        printf("<%d>", i + 1);
        scanf("%d", &arr[i]);
    }

    //Selection sort
    int lokasi_index;
    int nilai_min;

    for (j = 0; j <= (n - 2); j++) {
        lokasi_index = j;
        nilai_min = arr[j];

        for (k = j + 1; k <= (n - 1); k++) {
            if (nilai_min > arr[k]) {
                nilai_min = arr[k];
                lokasi_index = k;
            }
        }

        arr[lokasi_index] = arr[j];
        arr[j] = nilai_min;
    }

    //Tampilkan hasilnya
    printf("\n");
    printf("\n-----------------------\n");
    printf(" Elemen Array Yang Terurut\n");
    printf("\n-----------------------\n");

    for (l = 0; l < n; l++) {
        printf("%d\n", arr[l]);
    }

    return 0;
}
