#include <iostream>

using namespace std;

int nums[500000];

int is_in(int n, int E){
    int S = 0;
    int middle = 0;
    while(S <= E){
        middle = (S+E)/2;
        if(nums[middle]== n)
            return middle;
        else if(nums[middle] > n)
            E = middle - 1;
        else
            S = middle + 1;
    }
    return -1;
}

int main(){
    int N, Q;
    int b;

    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &nums[i]);
    }
    scanf("%d", &Q);
    for(int i=0;i<Q;i++){
        scanf("%d", &b);
        printf("%d ",is_in(b, N));
    }
    
    return 0;
}