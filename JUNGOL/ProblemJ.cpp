#include <iostream>

using namespace std;

const long long divider = 20091024;

long long pow(long long X, long long Y){
    if(Y == 0)
        return 1;
    if(Y%2){
        return (X*pow(X, Y-1))%divider;
    }
    else{
        long long Z = pow(X, Y/2);
        return (Z*Z)%divider;
    }
}

int main(){
    long long X, Y;

    cin >> X >> Y;
    cout << pow(X%divider, Y);
    return 0;
}