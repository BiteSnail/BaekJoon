#include <iostream>

using namespace std;

int parent[1000005];
int N, M; 

int find(int n){
    if(parent[n]==n)
        return n;
    return parent[n]=find(parent[n]);
}

void union_tree(int left, int right){
    int x = find(left);
    int y = find(right);

    if(x>y)
        parent[x] = y;
    else
        parent[y] = x;
}

int main(){
    int cmd, a, b;
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N >> M;
    for(int i=0;i<=N;i++)
        parent[i]=i;
    for(int i=0;i<M;i++){
        cin >> cmd >> a >> b;
        if(cmd){
            if(find(a)==find(b))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else{
            union_tree(a, b);
        }
    }
    return 0;
}