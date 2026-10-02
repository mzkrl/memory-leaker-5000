#include <stdio.h> 
int main() {  
    int arr[20]; //Array yang ingin dicari  
    int n; //Banyaknya array  
    int i;  
    //Dapatkan banyak elemen dalam array  
    while(1){   
        printf("\nMasukkan banyaknya angka yang berada dalam array: ");   
        scanf("%d", &n);   
        if((n>0) && (n<=20)) {    
            break;   
        }   
        else {    
            printf("Banyak array minimal harus 1 dan maksimum 20 elemen");
        }  
    }  
    //Masukkan elemen-elemen dalam array  
    printf("\n-----------------------\n");  
    printf(" Masukkan Elemen Array \n");  
    printf("\n-----------------------\n");    
    for(i=0; i<n; i++) {   
        printf("<%d>",i+1);   
        scanf("%d",&arr[i]);  
    }    
    char jwb;  
    int counter;    
    do {   
    //Masukkan angka yang ingin dicari   
    int item;   
    printf("\n------------------------------------");   
    printf("\nMasukkan elemen yang ingin dicari: ");   
    scanf("%d", &item);      
    //Lakukan binary search   
    int batas_bawah = 0;   
    int batas_atas = n - 1;      
    //Dapatkan indeks elemen yang berada paling tengah   
    int batas_tengah = (batas_bawah + batas_atas)/2;   
    int counter = 1; 
    while((item != arr[batas_tengah]) && (batas_bawah <= batas_atas)){    
        if(item > arr[batas_tengah]) {     
            batas_bawah = batas_tengah + 1;    
        }    
        else {     
            batas_atas = batas_tengah - 1;    
        }    
        batas_tengah = (batas_bawah + batas_atas)/2;    
        counter++;   
    }      
    if(item == arr[batas_tengah]) {    
        printf("\nAngka %d ditemukan pada posisi %d", item, batas_tengah + 1);   
    }   
    else {    
        printf("\nAngka %d tidak ditemukan dalam array", item);   
    }   printf("\nBanyaknya angka yang dibandingkan: %d\n", counter);   
    printf("\n\nIngin melakukan pencarian lagi ? ");   
    fflush(stdin);   
    scanf(" %c", &jwb);     
    } while ((jwb == 'y') || (jwb == 'Y'));    
return 0; 
} 