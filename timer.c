#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
int s = 59;
int main(){
    int t = 0;
    int m = 2;
    while(m != 0 || s != 0){
        if(s != 0 && t == 10){
            s--;
            t = 0;
        }
        else if(t == 10){
            m--;
            s = 59;
            t = 0;
        }
        Sleep(100);
        t++;
        system("cls");
        printf("timer - %d : %d",m,s);
        
    }
}