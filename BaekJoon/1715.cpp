#include <iostream>
#include <queue>
#include <vector>
using namespace std;

inline int getDeck(priority_queue<int, vector<int>, greater<int> > &cards){
    int temp = cards.top();
    cards.pop();
    return temp;
}

int main(){
    priority_queue<int, vector<int>, greater<int> > cards;
    int N, num;
    int result = 0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> num;
        cards.push(num);
    }

    while(cards.size()>1){
        int first = getDeck(cards);
        int second = getDeck(cards);
        result += first+second;
        cards.push(first+second);
    }
    cout<<result;
    return 0;
}