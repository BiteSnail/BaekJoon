#include <iostream>
#include <queue>
#define ii pair<int, int>

using namespace std;

int assemble[101][101];
bool is_middle[101];

int main(){
    int X, Y, K;
    int N, M;
    queue<ii> q;
    cin >> N;
    cin >> M;
    for(int m=0;m<M;m++){
        cin >> X >> Y >> K;
        if(X==N){
            q.push({Y, K});
            continue;
        }
        assemble[X][Y] = K;
        is_middle[X] = true;
    }

    while(!q.empty()){
        ii cur = q.front();
        q.pop();
        if(is_middle[cur.first]){
            for(int i=1;i<N;i++){
                if(assemble[cur.first][i]>0)
                    q.push({i, cur.second*assemble[cur.first][i]});
            }
        }
        else{
            assemble[N][cur.first] += cur.second;
        }
    }

    for(int i=1;i<N;i++){
        if(!is_middle[i]){
            printf("%d %d\n",i, assemble[N][i]);
        }
    }

    return 0;
}