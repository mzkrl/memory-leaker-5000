#include <stdio.h>
#include <string.h>
int main(){
    double x = 20000;
    long long total = (long long)(x * 100 + 0.5);  // jadi sen, +0.5 buat pembulatan
    long long bulat = total / 100;
    int sen = total % 100;
    
    char tmp[30];
    sprintf(tmp, "%lld", bulat);   // angka bulat jadi string "20000"
    int len = strlen(tmp);
    
    for (int a = 0; a < len; a++){
        if (a > 0 && (len - a) % 3 == 0) putchar('.');
        putchar(tmp[a]);
    }
    printf(".%02d\n", sen);
}