#include <iostream>
#include <queue>
using namespace std;

void break_tile(priority_queue<long long> &left_tile, int row, int col){
    if(row == 0 || col ==0){
        return;
    }
    if(row==col){
        left_tile.push(row);
    }
    else if(row > col){
        left_tile.push(col);
        break_tile(left_tile, row-col, col);
    }
    else{
        left_tile.push(row);
        break_tile(left_tile, row, col-row);
    }
}

int find_answer(priority_queue<long long> &wanted_tile, int m){
    priority_queue<long long> left_tile;
    long long cur;
    int cnt =1;
    
    left_tile.push(m);
    while(!wanted_tile.empty()){
        cur = wanted_tile.top();
        wanted_tile.pop();


        if(cur <= left_tile.top()){
            break_tile(left_tile, left_tile.top()-cur,left_tile.top());
            break_tile(left_tile,cur, left_tile.top()-cur);
        }
        else{
            left_tile.push(m);
            cnt++;
            break_tile(left_tile, left_tile.top()-cur,left_tile.top());
            break_tile(left_tile,cur, left_tile.top()-cur);
        }
        left_tile.pop();
    }

    return cnt;
}

int main(){
    priority_queue<long long> wanted_tile;
    long long n, m;
    int t;
    int temp;
    cin >> t;
    for(int j=0;j<t;j++){
        cin >> n >> m; 
        for(int i=0;i<n;i++){
            cin >> temp;
            wanted_tile.push((1<<temp));
        }
        cout<<"#"<<j+1<<" "<<find_answer(wanted_tile, m)<<endl;
    }
    
}