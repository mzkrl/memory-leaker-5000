#include <stdio.h>
#include <string.h>
typedef struct{ //pake struct, ini c bukan c++ yg bisa oop.
    char nama[50];
    int harga;
} buku;
buku daftar[]={
    {"Buku A", 10000},
    {"Buku B", 15000},
    {"Buku C", 20000},
    {"Buku D", 25000},
    {"Buku E", 30000},
    {"A", 10000},
    {"B", 9000},
    {"C", 8000},
    {"D", 7000},
    {"E", 6000},
    {"F", 5000},
    {"G", 4000},
    {"H", 3000},
    {"I", 2000},
    {"J", 1000}
};
char *isi(int n, const char *selection){
    if(strcmp(selection, "nama") == 0){
        return daftar[n].nama;
    }else if(strcmp(selection, "harga") == 0){
        static char buf[32];
        snprintf(buf, sizeof(buf), "%d", daftar[n].harga);
        return buf;
    }
    return NULL;
};
int jumlahbuku=sizeof(daftar)/sizeof(daftar[0]);
int main(){
    int a=sizeof(daftar)/sizeof(daftar[0]);
    int b=sizeof(daftar);
    int c=sizeof(daftar[0]);
    int n=1;
    printf("%d, %d, %d",a,b,c);
    printf("\n%s, %s", isi(n, "nama"), isi(n, "harga"));
}