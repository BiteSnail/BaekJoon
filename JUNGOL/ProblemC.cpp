#include <iostream>

using namespace std;

int matrix[100][100];

int dc[2]={1, -1};
int dr[2]={-1, 1};

bool is_in(int c, int r, int size){
    return (c>= 0 && c< size) && (r>=0 && r<size);
}

void set_matrix(int size){
    int cur_num = 1;
    bool upside = true;
    int r= 0, c= 0;

    matrix[c][r] = cur_num++;
    while(!(c==size-1 && r==size-1)){
        if(upside)
            if(c < size-1)
                c++;
            else
                r++;
        else
            if(r < size-1)
                r++;
            else
                c++;
        
        matrix[c][r] = cur_num++;
        while(is_in(c+dc[upside], r+dr[upside], size)){
            c += dc[upside]; r+=dr[upside];
            matrix[c][r] = cur_num++;
        }
        upside = !upside;
    }
}

int main(){
    int n;
    cin >> n;
    set_matrix(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}