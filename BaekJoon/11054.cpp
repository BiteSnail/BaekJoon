#include <iostream>

using namespace std;

int nums[1005];
int incline[1005];
int decline[1005];

int main()
{
    int n;
    int result = 0;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> nums[i];

    for(int i=0;i<n;i++){
        incline[i] = 1;
        for(int j=0;j<i;j++){
            if(nums[j] < nums[i]){
                incline[i] = max(incline[i], incline[j]+1);
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        decline[i] = 0;
        for(int j=n-1;j>i;j--){
            if(nums[j] < nums[i]){
                decline[i] = max(decline[i], decline[j]+1);
            }
        }
        result = max(result, incline[i]+decline[i]);
    }

    cout << result;
    return 0;
}