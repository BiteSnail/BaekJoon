#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int> > q;
vector<pair<int, int> > meets;

bool compare(const pair<int, int> & left,const pair<int, int> & right){
    if(left.second==right.second){
        return left.first < right.first;
    }
    return left.second < right.second;
}

bool compare2(const pair<int, int> & left,const pair<int, int> & right){
    if(left.first==right.first){
        return left.second < right.second;
    }
    return left.first < right.first;
}

int main(){
    int a, b;
    cin >> N;
    meets.resize(N);
    for(int i=0;i<N;i++){
        cin >> meets[i].first >> meets[i].second;
    }
    //sort(meets.begin(), meets.end(), compare);
    sort(meets.begin(), meets.end(), compare2);
    q.push(meets[0].second);

    for(int i=1;i<N;i++){
        if(q.top() <= meets[i].first){
            q.pop();
        }
        q.push(meets[i].second);
    }
    cout << q.size();
}