#include <iostream>

using namespace std;

int nums[1001];
int memo[1001];

int main(){
    int n;
    int result = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    
    for(int i=0;i<n;i++){
        memo[i] = 1;
        for(int j=0;j<i;j++){
            if(nums[j] < nums[i]){
                memo[i] = max(memo[i], memo[j]+1);
            }
        }
        result = max(memo[i], result);
    }
    cout << result;
    return 0;
}