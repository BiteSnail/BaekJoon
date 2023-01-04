#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int T, N;
int arr[110000];
string inputStr;
string P;

void splitToDeque(){
    int startIndex = 1;
    int sepIndex = 0;
    int i=0;

    while(sepIndex<inputStr.size()){
        if(inputStr[sepIndex]==','){
            arr[i++] = atoi(inputStr.c_str()+startIndex);
            startIndex = sepIndex+1;
        }
        sepIndex++;
    }
    if(inputStr[startIndex]!=']'){
        arr[i] = atoi(inputStr.c_str()+startIndex);
    }
    //DEBUG
    // for(i=0;i<N;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
}

void printResult(){
    bool isHead = true;
    int li =0, ri = N-1;
    for(int i=0;i<P.length(); i++){
        if(P[i]=='R')
            isHead = !isHead;
        else{
            if(N == 0){
                cout<<"error"<<endl;
                return;
            }
            isHead ? li++ : ri--;
            N--;
        }
    }
    cout<<'[';
    if(N>0){
        if(isHead){
            for(int i=li;i<ri; i++) //[front-back)
                cout<<arr[i]<<',';
            cout<<arr[ri];
        }
        else{
            for(int i=ri; i>li;i--) //(front-back]
                cout<<arr[i]<<',';
            cout<<arr[li];
        }
    }
    cout<<']'<<'\n';
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    for(int t=0;t<T;t++){
        cin >> P;
        cin >> N;
        cin >> inputStr;
        splitToDeque();
        printResult();
    }
    return 0;
}