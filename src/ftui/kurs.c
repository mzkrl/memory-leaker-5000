#include <stdio.h>
float usd = 17975, pound = 23792, sgd = 14038, euro = 20323, idr, cost, shipCost; //all ke idr
int c, i, j, N;
int input(const char *message, int *value){
    printf("%s", message);
    scanf("%d", value);
    return *value;
}
int choice(){
    input("\ncurrency apa?\n0. exit\n1. USD\n2. Pound\n3. SGD\n4. Euro\nchoice: ", &c);
    return c;
}
int mem(){
    float dat[N];
    for (i = 0; i < N; i++){
        dat[i] = 0;
    }
    printf("Data: ");
    for (i = 0; i < N; i++){
        printf("%.2f ", dat[i]);
    }
    return printf("\n");
}
int main(){
    switch(choice()){
        case 0:
            return 0;
        case 1:
            input("berapa USD? ", &N);
            idr = usd*N;
            printf("IDR = %.2f\n", idr);
            break;
        case 2:
            input("berapa Pound? ", &N);
            idr = pound*N;
            printf("IDR = %.2f\n", idr);
            break;
        case 3:
            input("berapa SGD? ", &N);
            idr = sgd*N;
            printf("IDR = %.2f\n", idr);
            break;
        case 4:
            input("berapa Euro? ", &N);
            idr = euro*N;
            printf("IDR = %.2f\n", idr);
            break;
        case 5:
            input("show memori?", &N);
            mem();
        default:
            printf("\nwrong choice, ulang");
            break;
    }
    return 0;
}
