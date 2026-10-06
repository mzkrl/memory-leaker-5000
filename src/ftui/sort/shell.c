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

    //Shell sort
    int incr, temp;

    for (incr = 3; incr > 0; incr--) {
        for (k = 0; k < incr; k++) {
            for (i = k; i < n; i += incr) {
                temp = arr[i];

                for (j = (i - incr); j >= 0; j -= incr) {
                    if (arr[j] > temp)
                        arr[j + incr] = arr[j];
                    else
                        break;
                }

                arr[j + incr] = temp;
            }
        }
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
