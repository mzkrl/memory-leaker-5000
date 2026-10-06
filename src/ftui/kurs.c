#include <stdio.h>
float usd = 17975, pound = 23792, sgd = 14038, euro = 20323, idr, cost, shipCost; //all ke idr
float dat[100];
int c, idx, geser, N, n, ongkir;
char *nm[] = {"", "USD", "Pound", "SGD", "Euro"};

int input(const char *message, int *value){
    int ch;
    printf("%s", message);
    if (scanf("%d", value) != 1){
        *value = -1;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
    return *value;
}
int choice(){
    input("\ncurrency apa?\n0. exit\n1. USD\n2. Pound\n3. SGD\n4. Euro\n5. show memori\n6. hapus memori\nchoice: ", &c);
    return c;
}
int mem(){
    printf("Data: ");
    for (idx = 0; idx < n; idx++){
        printf("%.2f ", dat[idx]);
    }
    return printf("\n");
}
float rate(int kode){
    if (kode == 1) return usd;
    if (kode == 2) return pound;
    if (kode == 3) return sgd;
    return euro;
}
void simpan(float x){
    if (n < 100){
        dat[n] = x;
        n++;
    } else {
        for (geser = 1; geser < 100; geser++){
            dat[geser - 1] = dat[geser];
        }
        dat[99] = x;
    }
}
void hitung(int kode){
    printf("berapa %s? ", nm[kode]);
    input("", &N);
    if (N < 0){
        printf("input salah\n");
        return;
    }
    idr = rate(kode) * N;
    printf("IDR = %.2f\n", idr);
    input("ongkir (IDR)? ", &ongkir);
    if (ongkir < 0){
        ongkir = 0;
    }
    shipCost = ongkir;
    cost = idr + shipCost;
    printf("Total = %.2f\n", cost);
    simpan(cost);
}
int main(){
    while (1){
        switch(choice()){
            case 0:
                return 0;
            case 1:
                hitung(1);
                break;
            case 2:
                hitung(2);
                break;
            case 3:
                hitung(3);
                break;
            case 4:
                hitung(4);
                break;
            case 5:
                mem();
                break;
            case 6:
                n = 0;
                for (idx = 0; idx < 100; idx++){
                    dat[idx] = 0;
                }
                printf("memori kosong\n");
                break;
            default:
                printf("\nwrong choice, ulang");
                break;
        }
    }
    return 0;
}