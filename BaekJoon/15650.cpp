#include <cstdio>
#include <iostream>

using namespace std;

bool check[9];
int arr[9];
int m, n;

void print(){
    for(int i=1;i<m;i++){
        printf("%d ",arr[i]);
    }
    printf("%d\n", arr[m]);
}

void bt2(int i){
    if(i>m){
        print();
    }
    else if(i==1){
        for(int j=1;j<=n;j++){
            if(check[j]==false){
                arr[i]=j;
                check[j]=true;
                bt2(i+1);
                check[j]=false;
            }
            
        }
    }
    else{
        for(int j=arr[i-1];j<=n;j++){
            if(check[j]==false){
                arr[i]=j;
                check[j]=true;
                bt2(i+1);
                check[j]=false;
            }
        }
    }
}

int main(){
    for(int i=0;i<9;i++) check[i]=false;
    scanf("%d %d", &n, &m);
    
    bt2(1);
    return 0;
}