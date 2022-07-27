#include <iostream>
#include <set>
#include <stack>

using namespace std;

int nums[150];
bool is_checked[150];
set<int> s;

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin>>nums[i];
        if(nums[i] == i){
            is_checked[i] = true;
            s.insert(i);
        }
    }
    
    for(int i=1;i<=n;i++){
        if(is_checked[i]==false){
            stack<int> st;
            st.push(nums[i]);
            while(st.top() != i){
                if(is_checked[st.top()]){
                    while(!st.empty()){
                        is_checked[st.top()] = false;
                        st.pop();
                    }
                    break;
                }
                is_checked[st.top()] = true;
                st.push(nums[st.top()]);
            }
            while(!st.empty()){
                s.insert(st.top());
                st.pop();
            }
        }
    }

    cout<<s.size()<<'\n';
    for(auto &e: s){
        cout<<e<<'\n';
    }

    return 0;
}