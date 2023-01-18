#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;
stack<int> index;
long long h[100010] = {0, };
long long result = 0;

int main(){

    while(true){
        cin >> N;
        if(N==0){
            break;
        }
        for(int i=0;i<N;i++){
            cin >> h[i];
        }
        h[N] = -1;
        index.push(0);

        for(int i=0;i<=N;i++){
            while(!index.empty() && h[index.top()] > h[i]){
                int height, width;
                height = index.top(); index.pop();
                width = index.empty() ? i : (i - index.top() -1);
                result = max(result, h[height] * width);
            }
            index.push(i);
        }

        cout<< result<<'\n';

    
        result = 0;
    }



    return 0;
}