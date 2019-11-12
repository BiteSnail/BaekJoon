#include <stdio.h>

int digit[10];

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0;i<10;i++){
        digit[i]=0;
    }
    while(n){
        digit[n%10]++;
        n/=10;
    }

    for(int i=9;i>=0;i--){
        for(int j=0;j<digit[i];j++){
            printf("%d",i);
        }
    }
    printf("\n");

    return 0;
}