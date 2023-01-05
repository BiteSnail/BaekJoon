#include <iostream>

using namespace std;

//N: count of sets.
//1<=N<=1,000,000 
//M: cout of instruction.
//time limit 2s.
//memory limit 128MB

/*
First approach
use std::set.
-expected problems
How do i check the number is in the some sets?
    use std::vector<set>? maybe it is too expensive.

Second approach
use array
but how?
the size of the arrayN is up to 1M+1.
부분임을 표현하기 위해서 사용할 수 있는 것은? id를 준다? 그러면 통합될 때마다 id를 전부 바꿔야 하는 문제점 발생

사이클을 이용한다.
case 1: 둘다 소속되지 않은 경우
서로의 인덱스를 가진다.
case 2: 한 쪽만 가진 경우
인덱스를 가진쪽의 값을 없는 쪽이 가지고 해당 인덱스의 값에 없는 쪽을 넣는다.
만약 1 3에서 하나만 숫자가 있다면? 있는 쪽이 가리키는 인덱스에 자기 자신을 넣고 그 인덱스를 자기 자신이 취한다.  
1 2 3     1 2 3
2 1       2 3 1
case3: 둘 다 소속된 경우
서로 값을 바꾼다
1 2 3 4   1 2 3 4   
2 1 4 3   4 1 2 3

위 케이스에서 안되는 경우가 있을까? 없을 듯?
되긴 하나 시간초과 발생
*/
int sets[1000100];
int N, M; 
int cmd, a, b;

void setIndex(){
    for(int i=0;i<=N;i++){
        sets[i] = -1;
    }
}

bool isInSame(int left, int right){
    int cycleNum = sets[left];
    while(cycleNum != -1){
        if(cycleNum == right)
            return true;
        else if(cycleNum == left){
            break;
        }
        cycleNum = sets[cycleNum];
    }
    return false;
}

void merge(int left, int right){
    if(sets[left]==-1 && sets[right]==-1){
        sets[left] = right;
        sets[right] = left;
    }
    else if(sets[left]>-1 && sets[right]>-1){
        int temp = sets[left];
        sets[left] = sets[right];
        sets[right] = temp;
    }
    else if(sets[left]>-1 && sets[right]==-1){
        sets[right] = sets[left];
        sets[left] = right;
    }
    else{
        sets[left] = sets[right];
        sets[right] = left;
    }
}

int main(){
    cin >> N >> M;
    setIndex();
    for(int i=0;i<M;i++){
        cin >> cmd >> a >> b;
        if(cmd){
            cout << (isInSame(a, b) ? "yes" : "no") <<endl;
        }
        else{
            merge(a, b);
        }
    }
    return 0;
}