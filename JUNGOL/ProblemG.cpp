#include <iostream>

using namespace std;

int queue[6];
int nums[13];
int K;

void print_col(int cur, int len){
    if(len == 6){
        for(int i=0;i<6;i++)
            printf("%d ",queue[i]);
        printf("\n");
    }
    else{
        for(int i=cur+1; i<K;i++){
            queue[len] = nums[i];
            print_col(i,len+1);
        }
    }
}

int main(){
    cin >> K;
    
    for(int k=0;k<K;k++){
        cin >> nums[k];
    }
    
    print_col(-1, 0);


    return 0;
}