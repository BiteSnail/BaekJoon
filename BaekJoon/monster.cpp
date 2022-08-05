#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> monster;

int main(void){
    int n;
    int level;
    int answer = 0;
    bool flag = false;
    cin >> n;
    monster.resize(n);
    for(int i=0;i<n;i++){
        cin >> monster[i];
    }

    sort(monster.begin(), monster.end());

    for(int i=0;i<monster.size();i++){
        level = monster[i] + i;
        flag = true;
        for(int j=i+1;j<monster.size();j++){
            if(level < monster[j]){
                flag = false;
                break;
            }
            level++;
        }
        if(flag)
            answer++;
    }

    cout <<answer<<endl;
    return 0;
}