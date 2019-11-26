#include <iostream>
#include <cstdio>

using namespace std;

int countt[15];

int solvee(int now){
    if(now<0){
        return 0;
    }
    
    if(countt[now]>0){
        return countt[now];
    }
    else{
        countt[now]=solvee(now-3)+solvee(now-2)+solvee(now-1);

        return countt[now];
    }
}

int main(void){
    int t;
    int n;
    countt[0]=1;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        scanf("%d", &n);
        printf("%d\n", solvee(n));
    }

    return 0;
}