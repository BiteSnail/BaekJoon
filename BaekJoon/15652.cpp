#include <iostream>
#include <cstdio>

int n, m;
int num[9];

void bt4(int now){
    if(now>m){
        for(int i=1;i<=m;i++)
            printf("%d ", num[i]);
        printf("\n");
    }
    else{
        for(int i=1;i<=n;i++){
            if(i>=num[now-1]){
                num[now]=i;
                bt4(now+1);
            }
        }
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    bt4(1);
}