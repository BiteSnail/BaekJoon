#include <iostream>
using namespace std;

int N;
int arr[1000100];
int result[1000100];
int t = -1;
int stack[1000100];

inline void push(int num){
    stack[++t] = num;
}

inline void pop(){
    t--;
}

inline bool empty(){
    return t==-1;
}

inline int top(){
    return stack[t];
}


int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%d", &arr[i]);
    
    for(int i=0;i<N;i++){
        while(!empty() && arr[top()]<arr[i]){
            result[top()] = arr[i];
            pop();
        }   
        push(i);
    }
    while(!empty()){
        result[top()] = -1;
        pop();
    }
    for(int i=0; i<N;i++){
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}