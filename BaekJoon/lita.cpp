#include <iostream>
#include <vector>

using namespace std;

vector<int> value(50);

int main(void){
    int n, x;
    int answer;
    int idx=0;
    cin >> n >> x;

    for(int i=0;i<n;i++){
        cin >> value[i];
    }

    for(int i=1;i<n;i++){
        if(value[i] > value[idx]){
            x = (x/value[idx])*value[i] + (x%value[idx]);
        }
        idx = i;
    }

    cout<< x;
    return 0;
}