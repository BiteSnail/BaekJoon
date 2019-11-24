#include <iostream>
#include <cstdio>

int max=-2000000000;
int min=2000000000;
int N[15];
int Oper[4];  // 0:+, 1:-, 2:*, 3:/
int n;

int calc(int op, int now, int cal){
    switch(op){
        case 0:
        cal+=N[now];
        break;
        case 1:
        cal-=N[now];
        break;
        case 2:
        cal*=N[now];
        break;
        case 3:
        cal/=N[now];
        break;
    }

    return cal;
}

void solve(int now, int cal){
    if(now==n){
        if(cal>max)
            max=cal;
        if(cal<min)
            min=cal;
    }
    else{
        for(int i=0;i<4;i++){
            if(Oper[i]>0){
                Oper[i]--;
                solve(now+1, calc(i, now, cal));
                Oper[i]++;
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &N[i]);
    }
    for(int i=0;i<4;i++){
        scanf("%d", &Oper[i]);
    }
    solve(1, N[0]);
    printf("%d\n", max);
    printf("%d\n", min);
    return 0;
}