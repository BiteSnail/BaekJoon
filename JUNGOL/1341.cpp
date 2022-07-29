#include <iostream>

using namespace std;

int main(){
    int s, e;
    int next = 0;
    cin >> s >> e;
    next = s>e ? -1 : 1;

    for(s;s!=e;s+=next){
        for(int i=1;i<=9;i++){
            printf("%d * %d = %2d   ", s, i, s*i);
            if(i%3==0){
                printf("\n");
            }
        }
        printf("\n");
    }
    for(int i=1;i<=9;i++){
        printf("%d * %d = %2d   ", s, i, s*i);
        if(i%3==0){
            printf("\n");
        }
    }
    return 0;
}