#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#define pii pair<int, int>
#define INT_MAX 2000000000

using namespace std;

int N, M;
int numbers[100010];
int maxSegTree[400000];
int minSegTree[400000];

void init(int cur, int left, int right){
    int mid = (left+right)/2;
    if(left<right){
        init(cur*2, left, mid);
        init(cur*2+1, mid+1, right);
        maxSegTree[cur] = max(maxSegTree[cur*2], maxSegTree[cur*2+1]);
        minSegTree[cur] = min(minSegTree[cur*2], minSegTree[cur*2+1]);
    }
    else if(left==right){
        maxSegTree[cur] = minSegTree[cur] = numbers[right];
    }
    else{
        maxSegTree[cur] = -1;
        minSegTree[cur] = INT_MAX;
        return;
    }
}

pii find_nums(int cur, int left, int right, int a, int b){
    int mid = (left+right) /2;
    if(left==a && right==b){
        return {minSegTree[cur], maxSegTree[cur]};
    }
    else if(right < a){
        return {INT_MAX, -1};
    }
    else if(b < left){
        return {INT_MAX, -1};
    }
    if(right <= mid){ //구하는 위치가 왼쪽에 있을 때
        return find_nums(cur*2, left, mid, a, b);
    }
    else if(left > mid){ //구하는 위치가 오른쪽에 있을 때
        return find_nums(cur*2+1, mid+1, right, a, b);
    }
    else{
        //int mid2 = (a+b)/2;
        pii lresult = find_nums(cur*2,left, mid, a, b > mid ? mid : b);
        pii rresult = find_nums(cur*2+1, mid+1, right, a < mid+1 ? mid+1 : a, b); 
        return {min(lresult.first, rresult.first), max(lresult.second, rresult.second)};
    }
}

int main(){
    int a, b;
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        scanf("%d", &numbers[i]);
    }
    init(1, 0, N-1);
    //cout << "min  " << "max" << '\n';
    // for(int i=1;maxSegTree[i];i++){
    //     cout << minSegTree[i] << "  " << maxSegTree[i] <<'\n';
    // }

    for(int i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        pii result = find_nums(1, 0, N-1, a-1, b-1);
        cout << result.first << ' ' << result.second <<'\n';
    }
    

    return 0;
}