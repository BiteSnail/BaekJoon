#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <deque>

using namespace std;

bool comp_l(const vector<int> &l, const vector<int> &r){
    return l[0]-l[1] < r[0]-r[1];
}

int main(void){
    deque<vector<int>> left;
    left.push_back({10, 20});
    left.push_back({30, 200});
    left.push_back({400, 50});
    left.push_back({30, 20});

    sort(left.begin(), left.end(), comp_l);
    
    for(auto &l : left){
        cout<< l[0] << ", " << l[1]<<endl;
    }
    
    return 0;
}