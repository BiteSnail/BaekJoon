#include <iostream>
#include <cstdio>
#include <cmath>

int stat[21][21];
int check[21];
int n;
int min=2100000000;
int st;
int li;

void solve(int now, int last){
    if(now==n/2){
        li=0;
        st=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(check[i]==1 && check[j]==1){
                    st+=stat[i][j];
                }
                else if(check[i]==0 && check[j]==0){
                    li+=stat[i][j];
                }
            }
        }
        if(abs(li-st) < min){
            min=abs(li-st);
        }
    }
    else{
        for(int i=last+1; i<n;i++){
            check[i]=1;
            solve(now+1, i);
            check[i]=0;
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d", &stat[i][j]);
    }
    check[0]=1;
    solve(1, 0);
    printf("%d\n",min);
    return 0;
}