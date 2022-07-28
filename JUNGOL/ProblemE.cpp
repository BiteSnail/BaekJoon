#include <iostream>
#include <cstring>
using namespace std;

int nums[150];
int cnt;
bool sel[150], is_checked[150];

bool is_ok(int s, int e){
    if(s==e){
        cnt++;
        return true;
    }
    if(is_checked[e]) 
        return false;
    is_checked[e]=true;
    return is_ok(s, nums[e]);
}

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }

    for(int i=1;i<=n;i++){
        memset(is_checked, false, sizeof(is_checked));
        sel[i] = is_ok(i, nums[i]);
    }

    cout<<cnt<<'\n';
    for(int i=1;i<=n;i++){
        if(sel[i])
            cout<<i<<'\n';
    }
    return 0;
}