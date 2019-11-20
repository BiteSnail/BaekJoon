#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<int> adjList[1001];
bool visited[1001];

void dfs(int cur){
    visited[cur]=true;
    printf("%d ", cur);

    for(int i=0;i<adjList[cur].size();i++){
        if(visited[adjList[cur][i]]==false){
            dfs(adjList[cur][i]);
        }
    }
}

int main(){
    int n, e, s;
    int x, y;
    scanf("%d %d %d", &n, &e, &s);
    for(int i=0;i<e;i++){
        scanf("%d %d", &x, &y);
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        sort(adjList[i].begin(), adjList[i].end());
    }
    dfs(s);
    return 0;
}