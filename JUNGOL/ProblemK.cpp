#include <iostream>
#include <queue>
#define ii pair<int, int>
using namespace std;

int heights[80000];

int sum;

int main(){
    int N;
    int pivot, l, r;
    queue<ii> task_q;
    cin >> N;
    for(int n=0;n<N;n++){
        cin >> heights[n];
    }
    task_q.push({0, N});
    while(!task_q.empty()){
        l = task_q.front().first;
        r = task_q.front().second;
        task_q.pop();
        pivot = l+1;
        if(l>=r){
            return;
        }
        while(pivot < r){
            if(heights[l]<=heights[pivot]){
                break;
            }
            pivot++;
        }
        sum += (pivot - l - 1);
        task_q.push({l+1, pivot});
        task_q.push({pivot, r});
    }
    cout<<sum;

    return 0;
}