#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    for(int n=1;n<=N;n++){
        for(int m=0; m<N; m++){
            printf("%d ", m*N+n);
        }
        printf("\n");
    }
    return 0;
}