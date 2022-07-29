#include <iostream>

using namespace std;

void sel1(int N){
    for(int i=1;i<=N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",i);
        }
        printf("\n");
    }
}

void sel2(int N){
    for(int i=0;i<N;i++){
        if(i%2==0)
        for(int j=1;j<=N;j++){
            printf("%d ", j);
        }
        else
        for(int j=N;j>=1;j--){
            printf("%d ", j);
        }
        printf("\n");
    }
}

void sel3(int N){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            printf("%d ",i*j);
        }
        printf("\n");
    }
}

int main(){
    int N, M;
    cin >> N>> M;
    switch(M){
        case 1:
            sel1(N);
            break;
        case 2:
            sel2(N);
            break;
        case 3:
            sel3(N);
            break;
        default:
            break;
    }
    
    return 0;
}