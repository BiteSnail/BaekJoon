#include <iostream>

using namespace std;

int main(){
    int N, M;
    int num = 1;
    cin >> N >> M;
    for(int n=0;n<N;n++){
        if(n%2==0)
        for(int m=1;m<=M;m++){
            printf("%d ", n*M+m);
        }
        else
        for(int m=M; m>0; m--){
            printf("%d ", n*M+m);
        }
        printf("\n");
    }
    return 0;
}