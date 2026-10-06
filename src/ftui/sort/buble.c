#include <stdio.h>

int main()
{
    int arr[20]; // Array yang ingin dicari
    int n;       // Banyaknya array
    int i, j, k, l;

    // Dapatkan banyak elemen dalam array
    while (1)
    {
        printf("\nMasukkan banyaknya angka yang berada dalam array: ");
        scanf("%d", &n);

        if ((n > 0) && (n <= 20))
        {
            break;
        }
        else
        {
            printf("Banyak array minimal harus 1 dan maksimum 20 elemen");
        }
    }

    // Masukkan elemen-elemen dalam array
    printf("\n-----------------------\n");
    printf(" Masukkan Elemen Array \n");
    printf("\n-----------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("<%d>", i + 1);
        scanf("%d", &arr[i]);
    }

    // Bubble sort
    for (j = 1; j < n; j++) // Untuk lintasan n - 1
    {
        // Dalam lintasan ke i, bandingkan elemen n-i pertama dengan elemen berikutnya
        for (k = 0; k < n - j; k++)
        {
            if (arr[k] > arr[k + 1]) // Jika elemen tidak berurutan
            {
                // Tukar elemennya
                int temp;

                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }

    // Tampilkan hasilnya
    printf("\n");
    printf("\n-----------------------\n");
    printf(" Elemen Array Yang Terurut\n");
    printf("\n-----------------------\n");

    for (l = 0; l < n; l++)
    {
        printf("%d\n", arr[l]);
    }

    return 0;
}