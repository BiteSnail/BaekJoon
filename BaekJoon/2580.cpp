#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>

using namespace std;

typedef struct _pos{
    int row;
    int col;
}POS;
vector <POS> p;

int sudoku[9][9];
int flag;

void printarr(){
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            printf("%d ", sudoku[row][col]);
        }
        printf("\n");
    }
}

void check1(int sq[],POS pp){
    for(int i=1;i<=9;i++)
        sq[i]=0;
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(sudoku[(pp.row/3)*3+row][(pp.col/3)*3+col]>0)
                sq[sudoku[(pp.row/3)*3+row][(pp.col/3)*3+col]]=1;
        }
    }
}

void check2(int sq[],POS pp){
    for(int i=1;i<=9;i++){
        sq[sudoku[pp.row][i-1]]=sq[sudoku[i-1][pp.col]]=1;
    }
}

void doku(int now){
    int sq[10];
    // printf("%d\n",now);
    if(now==p.size()){
        flag=1;
        printarr();
    }
    else{
        check1(sq,p[now]);
        check2(sq,p[now]);
        // for(int i=1;i<=9;i++)
        //     printf("%d ", sq[i]);
        // printf("\n");
        for(int i=1;i<=9;i++){
            if(flag==1)
                return;
            if(sq[i]==0){
                sudoku[p[now].row][p[now].col]=i;
                //printarr();
                doku(now+1);
                sudoku[p[now].row][p[now].col]=0;
            }
        }
    }
}

int main(){
    POS pp;
    flag=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d", &sudoku[i][j]);
            if(sudoku[i][j]==0){
                pp.row=i; pp.col=j;
                p.push_back(pp);
            }
        }
    }
    //printf("%d\n", p.size());
    doku(0);

    return 0;
}