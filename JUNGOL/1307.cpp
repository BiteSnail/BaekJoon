#include <iostream>

using namespace std;

int main(){
    int N;
    int m;
    cin >> N;
    m = N*N-1;

    for(int i=N-1;i>=0;i--){
        for(int j=N-1;j>=0;j--){
            printf("%c ", 'A'+(i+j*N)%26 );
        }
        printf("\n");
    }
    
    return 0;
}