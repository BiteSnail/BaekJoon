#include <iostream>
#include <stack>
#include <deque>
#define pii pair<int, int>
using namespace std;

int N;
deque<int> tower;
stack<int> sig;

int main(){
    cin >> N;
    tower.resize(N);
    for(int i=0;i<N;i++)
        cin >> tower[i];
    
    for(int i=N-1; i>=0;i--){
        while(!sig.empty() && (tower[sig.top()] < tower[i])){
            tower[sig.top()] = i;
            sig.pop();
        }
        sig.push(i);
    }
    while(!sig.empty()){
        tower[sig.top()]=-1;
        sig.pop();
    }
    for(int i=0;i<N;i++){
        cout<<tower[i]+1<<' ';
    }
    cout<<'\n';
}