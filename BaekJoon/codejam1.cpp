#include <iostream>
#include <deque>

using namespace std;

void get_data(deque<int> &pancakes){
    int N;
    cin>>N;
    pancakes.resize(N);
    for(int i=0;i<N;i++){
        cin>>pancakes[i];
    }
}

void print_answer(const int T, const int ans){
    cout<<"Case #"<<T<<": "<<ans<<endl;
}

int find_maximum(deque<int> &pancakes){
    int left = 0;
    int right = pancakes.size()-1;
    int last = min(pancakes[left],pancakes[right]);
    int ans = 0;
    while(left <= right){
        if(pancakes[left] < pancakes[right]){
            if(last <= pancakes[left]){
                ans++;
                last = pancakes[left];
            }
            left++;
        }
        else{
            if(last <= pancakes[right]){
                ans++;
                last = pancakes[right];
            }
            right--;
        }
    }
    return ans;
}

int main(void){
    int T;
    
    deque<int> pancakes;
    cin>> T;
    for(int i=0;i<T;i++){
        get_data(pancakes);
        print_answer(i+1, find_maximum(pancakes));
    }

    return 0;
}