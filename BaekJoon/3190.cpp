#include <iostream>

using namespace std;

//Rules
//if snake touch the wall or his body, game end.
//1. Locate at next position by stretching size of body
//2. If apple is in the position, remove apple and dont move tail
//3. If apple is not in the position, shrink that's size
//Left: L, Right: D

enum DIR{
    RIGHT,
    DOWN,
    LEFT,
    UP
};

enum BOARD{
    ROW,
    COL
};

typedef struct POS{
    int row;
    int col;
}POS;

int N; //Size of board 
int K; //Amount of apple
int L; //Counts of rotation

const int STEP[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

bool isIn(const POS pos){
    return (pos.row >=0 && pos.row < N) &&
            (pos.col >=0 && pos.col < N);
}

POS moveTo(const POS pos, const int dir){
    POS next = pos;
    next.row += STEP[dir][ROW];
    next.col += STEP[dir][COL];
    return next;
}

int rotate(const int dir, const char X){
    int next = (dir + (X == 'D' ? 1 : -1))%4;
    return next < 0 ? UP : next;
}

int main(){
    int dir = RIGHT;
    for(int i=0;i<4;i++){
        cout<<dir<<endl;
        dir = rotate(dir, 'L');
    }
    
    return 0;
}