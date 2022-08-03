#include <iostream>
#include <queue>
using namespace std;

bool graph[2][1001][1001];
bool visited[2][1001];

int main(){
    queue<pair<int, int>> bfs;
    int n, m;
    int a, b;
    int cur, time;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        graph[0][a][b]=graph[1][b][a]=true;
    }

    bfs.push(make_pair(1, 0));
    visited[0][1]=true;
    while(!bfs.empty()){
        cur = bfs.front().first;
        time = bfs.front().second;
        bfs.pop();
        //cout<< cur <<", "<<time<<"hours"<<endl;
        if(cur == n){
            break;
        }

        for(int i=1;i<=n;i++){
            if(graph[time%2][cur][i] && visited[(time+1)%2][i]==false){
                bfs.push(make_pair(i, time+1));
                visited[(time+1)%2][i]=true;
            }
        }
        if(visited[(time+1)%2][cur]==false)
            bfs.push(make_pair(cur, time+1));
    }

    if(cur ==n){
        cout<< time <<endl;
    }
    else{
        cout<< -1 <<endl;
    }

    return 0;
}