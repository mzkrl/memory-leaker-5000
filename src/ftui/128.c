#include <stdio.h>  
int main() { 
    int arr[20]; //array yang ingin dicari  
    int n; //jumlah elemen dalam array  
    int i;  //Dapatkan banyak elemen dalam array  
    while(1){   
        printf("\nMasukkan banyaknya angka yang berada dalam array: ");   
        scanf("%d", &n);   if((n>0) && (n<=20)) {    
            break;   
        }   else {    
            printf("\nBanyak array minimal harus 1 dan maksimum 20 elemen");   
        }  
    }  //Masukkan elemen-elemen dalam array  
    printf("\n-----------------------\n");  
    printf(" Masukkan Elemen Array \n");  
    printf("\n-----------------------\n");
    for(i=0; i<n; i++) {   
        printf("<%d>",i+1);
        scanf("%d",&arr[i]);  
    }
    char jwb;  
    int counter;  
    do {   //Masukkan angka yang ingin dicari    
    int item;   
    printf("\n------------------------------------");   
    printf("\nMasukkan elemen yang ingin dicari: ");   
    scanf("%d", &item);   //Lakukan sequential search   
    counter = 0;   
    for(i=0; i<n; i++) {    
        counter++;    
        if(arr[i] == item){     
            printf("\nAngka %d ditemukan pada posisi %d\n", item, i+1);     
            jwb = 'n';     
            break;    
        }   
    }   
    if(i == n){    
        printf("\nAngka %d tidak ditemukan dalam array\n", item);    
        printf("\nBanyaknya angka yang dibandingkan: %d\n", counter);    
        printf("\n\nIngin melakukan pencarian lagi ? ");    
        fflush(stdin);    scanf("%c", &jwb);   
        }  
    } 
    while ((jwb == 'y') || (jwb == 'Y'));  
    return 0; 
} 