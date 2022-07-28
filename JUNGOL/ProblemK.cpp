#include <iostream>
#include <stack>
#define ii pair<int, int>
using namespace std;

long long sum;
//maximum data 80000
//80000*79999/2 = 3199960000 is bigger than int type
//^^;;

int main(){
    int N;
    int h;
    stack<ii> cow;
    ii tp;
    cin >> N;
    cin >> h;
    cow.push({h, 1});
    for(int n=1;n<N;n++){
        cin >> h;
        if(cow.top().first > h){
            cow.push({h, 1});
        }
        else{
            while(!cow.empty()){
                if(cow.top().first > h){
                    break;
                }
                tp = cow.top();
                cow.pop();
                if(!cow.empty())
                    cow.top().second += tp.second;
                sum += tp.second-1;
            }
            cow.push({h, 1});
        }
    }
    while(!cow.empty()){
        tp = cow.top();
        cow.pop();
        if(!cow.empty())
            cow.top().second += tp.second;
        sum += tp.second-1;
    }
    cout<<sum;

    return 0;
}