#include <iostream>

using namespace std;

int main(){
    int N, M;
    int num = 1;
    cin >> N >> M;
    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            printf("%d ", num++);
        }
        printf("\n");
    }
    return 0;
}