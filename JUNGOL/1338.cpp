#include <iostream>

using namespace std;

int mat[100][100];

int main(){
    int N;
    int r, c;
    int count = 0;
    cin >> N;

    for(int i=N;i>0;i--){
        for(c = N-i, r = N-1;c<N;c++, r--){
            mat[c][r] = 'A' + (count++)%26;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mat[i][j]==0)
            printf("  ");
            else
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}