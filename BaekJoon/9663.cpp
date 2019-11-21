#include <iostream>
#include <cstdio>
#include <cmath>

int n;
int col[20];
int count;

void nqueen(int now){
    int flag;

    if(now==n)
        count++;
    else{
        for(int i=0;i<n;i++){
            flag=1;
            for(int j=0;j<now;j++){
                if(col[j]==i || abs(col[j]-i)==now-j){
                    flag=0;
                    break;
                }
            }
            if(flag){
                col[now]=i;
                nqueen(now+1);
            }
        }
    }
}

int main(){
    scanf("%d", &n);

    nqueen(0);

    printf("%d\n", count);
    return 0;
}