#include <iostream>
#include <cstdio>

int m, n;
int num[9];

void bt3(int i){
    if(i==m){
        for(int j=0;j<m;j++)
            printf("%d ", num[j]);
        printf("\n");
    }
    else{
        for(int j=1;j<=n;j++){
            num[i]=j;
            bt3(i+1);
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    bt3(0);
    return 0;
}