#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;
int A, B;
vector<int> prob[32001];
priority_queue<int, vector<int>, greater<int> > q;
int connect[33000];

int main(){
    cin >> N >> M;
    
    for(int i=0;i<M;i++){
        cin >> A >> B;
        prob[A].push_back(B);
        connect[B]++;
    }

    for(int i=1;i<=N;i++){
        if(connect[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int cur = q.top();
        q.pop();
        cout<< cur << ' ';
        for(int i=0;i<prob[cur].size();i++){
            connect[prob[cur][i]]--;
            if (!connect[prob[cur][i]])
                q.push(prob[cur][i]);
        }
    }
    return 0;
}