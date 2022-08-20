#include <iostream>

using namespace std;

int N;
int answer;
int Cq[100];

void NQUEEN(int qn, int mask){
    if(qn==N)
        answer++;
    else{
        for(int i=0;i<N;i++){
            if(mask & (1<<i) == false){
                
            }
        }
    }
}

int main(){
    cin >> N;
    NQUEEN(0, 0);
    cout<< answer;
    return 0;
}