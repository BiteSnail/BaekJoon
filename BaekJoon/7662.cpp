#include <iostream>
#include <set>
using namespace std;

int T;
int Q;

int main(){
    multiset<int> dual_que;
    char command;
    int option;

    cin >> T;
    for(int i=0;i<T;i++){
        cin >> Q;
        for(int j=0;j<Q;j++){
            cin >> command >> option;
            switch(command){
                case 'I':
                    dual_que.insert(option);
                break;
                case 'D':
                    if(dual_que.size()==0)
                        break;
                    if(option>0){
                        auto iter = dual_que.end();
                        iter--;
                        dual_que.erase(iter);
                    }
                    else
                        dual_que.erase(dual_que.begin());
                break;
                default:
                break;
            }
        }
        if(dual_que.size())
            cout << *dual_que.rbegin() << ' ' << *dual_que.begin() << '\n';
        else
            cout<< "EMPTY\n";
        dual_que.clear();
    }
    
    return 0;
}