#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct meeting{
    int id;
    int s_time;
    int e_time;
};

int N;

meeting meetings[500];
queue<int> q;

bool compare(const meeting &a, const meeting &b){
    if(a.e_time == b.e_time){
        return a.s_time > b.s_time;
    }
    else{
        return a.e_time < b.e_time;
    }
}

int main(){
    int s=0, e=0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> meetings[i].id >> meetings[i].s_time >> meetings[i].e_time;
    }

    sort(meetings, meetings+N, compare);

    for(int i=0;i<N;i++){
        if(meetings[i].s_time >= e){
            q.push(meetings[i].id);
            e = meetings[i].e_time;
        }
    }

    cout << q.size()<<'\n';
    while(!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
}