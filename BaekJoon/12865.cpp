#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int normal_bag(vector<pair<int, int>> items, int k){
    //int result= 0;
    map<int, int> memo;
    //sort(items.begin(), items.end());

    for(int i=0;i<items.size();i++){
        
    }

    // for(auto it : memo){
    //     cout<<it.first <<", " <<it.second<<endl;
    //     //result = max(result, it.second);
    // }
    return memo[k];
}

int main(){
    vector<pair<int, int>> items; //first : weight, second : value
    int n, k;
    cin >> n >> k;
    items.resize(n);

    for(int i=0;i<n;i++){
        cin >> items[i].first >> items[i].second;
    }
    
    cout<<normal_bag(items, k)<<endl;

    return 0;
}