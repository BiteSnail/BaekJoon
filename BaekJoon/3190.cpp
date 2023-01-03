#include <iostream>
#include <algorithm>
#include <set>
#include <deque>

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

    bool operator==(const struct POS& other) const {
        return (row == other.row) && (col == other.col);
    }
    bool operator<(const struct POS& other) const {
        if (row == other.row)
            return col < other.col;
        return row < other.row;
    }
}POS;

int N; //Size of board 
int K; //Amount of apple
int L; //Counts of rotation
set<POS> apples;
deque<POS> snake;
POS pos;
int curTime = 1;
int curDir = RIGHT;
char rotationDir;
int result = 0;

const int STEP[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

bool isIn(const POS pos){
    return (pos.row >0 && pos.row <= N) &&
            (pos.col >0 && pos.col <= N);
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

bool isTouched(const deque<POS>& snake){
    return find(snake.begin(), snake.end()-1, snake.back())==snake.end()-1 ? false : true;
}

bool goForward(const int nextTime=1000000){
    for(; curTime <= nextTime; curTime++){
        POS nextPos = moveTo(snake.back(), curDir);
        snake.push_back(nextPos);
        if(isIn(nextPos) && !isTouched(snake)){
            auto iter = apples.find(nextPos);
            if(iter==apples.end()){
                snake.pop_front();
            }
            else{
                apples.erase(iter);
            }
        }
        else{
            result = curTime;
            return true;
        }
    }
    return false;
}

int main(){
    int nextTime = 0;
    bool isDone = false;
    cin >> N;
    cin >> K;
    for(int k=0;k<K;k++){
        cin >> pos.row >> pos.col;
        apples.insert(pos);
    }
    cin >> L;
    snake.push_back({1, 1});
    for(int l=0;l<L;l++){
        cin >> nextTime >> rotationDir;
        if(isDone) {
            continue;
        }
        isDone = goForward(nextTime);
        curDir = rotate(curDir, rotationDir);
    }
    if(!isDone)
        goForward();
    cout<<result;
    return 0;
}