#include <iostream>

using namespace std;

int mat[100][100];

int main(){
    int N;
    int count;
    cin >> N;
    if(N%2==0 || N < 0 || N > 100){
        printf("INPUT ERROR");
        return 0;
    }
    count = (N/2+1)*(1+N)/2-1;
    
    for(int i=0;i<= N/2;i++){
        for(int j=N-i-1;j>=i;j--){
            mat[j][i] = 'A' + (count--)%26;
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