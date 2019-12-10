#include <iostream>
#include <cstdio>

int num[1005];
int count[1005];
int res=0;

int max(int a, int b){
    return a>b ? a: b;
}

int solve(int now){
    int next=now-1;
    if(count[now]>0)
        return count[now];
    
    while(next>=0){
        if(num[next]<num[now]){

        }
    }
}

int main(){
    int n;
    for(int i=0;i<1005;i++)
        count[i]=0;

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &num[i]);
    }    
    solve(n);
}