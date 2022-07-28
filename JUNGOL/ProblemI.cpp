#include <iostream>

using namespace std;

char matrix[128][128];
int bw[2];

bool check_bw(int n, int c, int r){
    char l = matrix[c][r];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%c", matrix[c+i][r+j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(l != matrix[c+i][r+j])
                return false;
        }
    }
    return true;
}

void get_bw(int n, int c, int r){
    if(check_bw(n, c, r)){
        bw[matrix[c][r]-'0']++;
        return;
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            //printf("%d %d\n", c+(n/2)*i, r+(n/2)*j);
            get_bw(n/2, c+(n/2)*i, r+(n/2)*j);
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf(" %c", &matrix[i][j]);
        }
    }

    get_bw(N, 0, 0);

    printf("%d\n%d",bw[0], bw[1]);
    
    return 0;
}