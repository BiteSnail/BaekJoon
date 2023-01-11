#include <iostream>
#include <queue>
#include <set>

using namespace std;

int N;
int M;

bool isConnect[205][205];
int parent[205];
bool visited[205];
bool flag = true;
int cityNum;
int prevParent = -1;

void setParent(){
    queue<int> que;
    for(int i=0;i<N;i++){
        if(visited[i])
            continue;
        que.push(i); //BFS
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            for(int next=0;next<N;next++){
                if(!visited[next] && isConnect[cur][next]){
                    que.push(next);
                    visited[next]=true;
                    parent[next] = i;
                }
            }
        }
    }
}

int main(){
    cin >> N;
    cin >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> isConnect[i][j];
        }
        parent[i] = i;
    }

    setParent();

    for(int i=0;i<M;i++){
        cin>>cityNum;
        if(prevParent == -1){
            prevParent = parent[cityNum-1];
        }
        else{
            flag = flag ? prevParent == parent[cityNum-1] : flag;
        }
    }

    switch(flag){
        case true:
            cout<<"YES";
            break;
        case false:
            cout<<"NO";
            break;
    }
    return 0;
}