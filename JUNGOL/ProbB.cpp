#include <iostream>
using namespace std;

int W;
int n = 0;
int coins[6];
int values[6] = {500, 100, 50, 10, 5, 1};
int counts[6];

int main(){
    cin >> W;
    
    for(int i=0;i<6;i++){
        cin >> coins[i];
    }
    
    for(int i=5;i>0;i--){
        if(W==0)
            break;
        counts[i] = coins[i];
        while((W-(counts[i]*values[i]))%values[i-1]){
            counts[i]--;
        }
        n += counts[i];
        W-= counts[i] * values[i];
    }
    if(W){
        counts[0] = W/values[0];
        n+=counts[0];
    }

    cout<< n <<'\n';
    for(int i=0;i<6;i++){
        cout<< counts[i] <<' ';
    }
    return 0;
}