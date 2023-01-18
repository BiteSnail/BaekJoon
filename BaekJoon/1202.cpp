#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
#define pii pair<int, int>

using namespace std;

int N, K;
deque<pii> jual;
deque<int> C;
long long result = 0;

void printSortedArray(){
    for(int i=0;i<N;i++){
        cout << jual[i].first << ' ' << jual[i].second<<';';
    }
    cout << endl;
    for(int i=0;i<K;i++){
        cout << C[i] << ' ';
    }
    cout<< endl;
}

int main(){
    int prevIndex = 0;
    priority_queue<int> values;
    cin >> N >> K;
    C.resize(K);
    jual.resize(N);

    for(int i=0;i<N;i++){
        cin >> jual[i].first >> jual[i].second;
    }
    for(int i=0;i<K;i++){
        cin >> C[i];
    }
    sort(jual.begin(), jual.end());
    sort(C.begin(), C.end());

    for(int i=0;i<K;i++){
        while(prevIndex < N && jual[prevIndex].first <= C[i]){
            values.push(jual[prevIndex].second);
            prevIndex++;
        }
        if(values.empty())
            continue;
        result += values.top();
        values.pop();
    }
    printf("%lld\n", result);
    return 0;
}