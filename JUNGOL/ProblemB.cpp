#include <iostream>
using namespace std;

char matrix[200][200];

int dr[4] = {-1, 1, 1, -1};
int dc[4] = {1, 1, -1, -1};

char set_border(char a, int n, int r, int c){
    int nc = c;
    int nr = r;
    matrix[nc][nr] = a;
                a++;
                if(a>'Z')
                    a = 'A';
    for(int d=0;d<4;d++){
        for(int i=1;i<n;i++){
            nc += dc[d];
            nr += dr[d];
            if(nc == c && nr == r){
                continue;
            }
            matrix[nc][nr] = a;
            a++;
            if(a>'Z')
                a = 'A';
        }
    }

    return a;
}

int main(void){
    int n;
    int middle;
    char alpha = 'A';
    cin >> n;
    middle = n-1;
    for(int f=0;f<n;f++){
        alpha = set_border(alpha, n-f, middle, f);
    }

    for(int i=0; i < 2*n-1; i++){
        for(int j=0; j< 2*n -1; j++){
            printf("%c ", matrix[i][j] > 0 ? matrix[i][j] : ' ');
        }
        printf("\n");
    }

    return 0;
}