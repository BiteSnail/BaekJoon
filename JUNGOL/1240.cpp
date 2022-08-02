#include <iostream>

using namespace std;

long long sqlt(long long n, long long l){
    if(l*l > n){
        return sqlt(n, l/2);
    }
    else if(l*l == n){
        return l;
    }
    else{

    }
}

int main(){
    long long N;
    long long l;
    cin >> N;
    

    return 0;
}