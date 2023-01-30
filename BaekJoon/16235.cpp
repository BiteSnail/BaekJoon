#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define pii pair<int, int>
using namespace std;

int N, M, K;
int nutritionAmount[11][11];
int S2D2[11][11];
int dir[8][2] = {
    {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
    {1, 0}, {1, -1}, {0, -1}, {-1, -1}
};
priority_queue<int, vector<int>, greater<int> > treeAges[11][11];
vector<pii> expandTreePos;

vector<int> trees[11][11];

bool isIn(const int &row, const int &col){
    return (row>=0 && row<N) && (col>=0 && col<N);
}

void spring(const int &row, const int &col){
    priority_queue<int, vector<int>, greater<int> > nextTreeAges;
    vector<int> nextTrees;
    int nutrition = 0;
    // while(!treeAges[row][col].empty()){
    //     int curAge = treeAges[row][col].top();
    //     treeAges[row][col].pop();

    //     if(curAge>nutritionAmount[row][col]){
    //         nutrition += curAge/2;
    //         continue;
    //     }

    //     nutritionAmount[row][col] -= curAge;
    //     nextTreeAges.push(curAge+1);

    //     if((curAge+1)%5==0){
    //         expandTreePos.push_back({row, col});
    //     }
    // }
    sort(trees[row][col].begin(), trees[row][col].end());
    for(int i=0;i<trees[row][col].size();i++){
        if(trees[row][col][i] > nutritionAmount[row][col]){
            nutrition += trees[row][col][i]/2;
            continue;
        }
        nutritionAmount[row][col] -= trees[row][col][i];
        nextTrees.push_back(trees[row][col][i]+1);

        if(nextTrees.back()%5==0)
            expandTreePos.push_back(make_pair(row, col));
    }
    // treeAges[row][col] = nextTreeAges;
    trees[row][col] = nextTrees;
    nutritionAmount[row][col] += nutrition;
}

void fall(){
    for(auto &cur:expandTreePos){
        for(int i=0;i<8;i++){
            pii nextPos = {cur.first + dir[i][0], cur.second+dir[i][1]};
            if(isIn(nextPos.first, nextPos.second))
                trees[nextPos.first][nextPos.second].push_back(1);
        }
    }
    expandTreePos.clear();
}

void winter(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            nutritionAmount[i][j] += S2D2[i][j];
        }
    }
}

void setDefault(){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            nutritionAmount[i][j] = 5;
}

int getresult(){
    int row, col, age;
    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> S2D2[i][j];
        }
    }
    for(int i=0;i<M;i++){
        cin >> row >> col >> age;
        trees[row-1][col-1].push_back(age);
    }
    setDefault();
    for(int i=0;i<K;i++){
        for(int row=0;row<N;row++){
            for(int col=0;col<N;col++){
                spring(row, col);
            }
        }
        fall();
        winter();
    }
    int result =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            result += trees[i][j].size();
        }
    }
    return result;
}

int main(){
    // while(1){
        cout<<getresult()<<'\n';
    // }
    return 0;
}