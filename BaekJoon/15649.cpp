#include <iostream>
#include <cstdio>

using namespace std;

bool check[9];
int m;
int n;

void printarr(int arr[]){
    for(int i=1;i<m;i++){
        printf("%d ",arr[i]);
    }
    printf("%d\n",arr[m]);
}
void bt(int arr[], int j){
    if(j>m){
        printarr(arr);
    }
    else{
        for(int i=1;i<=n;i++){
            if(check[i]==false){
                arr[j]=i;
                check[i]=true;
                bt(arr, j+1);
                check[i]=false;
            }
        }
    }
}

int main(){
    int arr[9];
    for(int i=0;i<9;i++){
        check[i]=false;
    }
    scanf("%d %d", &n, &m);
    bt(arr, 1);
    return 0;
}