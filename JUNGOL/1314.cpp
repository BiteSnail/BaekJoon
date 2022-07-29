#include <iostream>

using namespace std;

int mat[100][100];

int main(){
    int N;
    int m;
    char next;
    cin >> N;
    m = N*N-1;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            mat[j][i] = i%2==0 ? 'A'+(i*N+j)%26: 'A'+(i*N+(N-j-1))%26;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}