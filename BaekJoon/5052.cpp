#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int T;
int N;
string phoneNumbers[10010];

typedef struct TRIE{
    bool is_end = false;
    struct TRIE *child[10] = {0, };
}TRIE;

//911

bool isPrefix(int I, TRIE *cur, string & phoneNumber){
    if(I==phoneNumber.length()){
        cur->is_end = true;
        return false;
    }
    int index = (phoneNumber[I] - '0');
    if(cur->is_end){
        return true;
    }
    if((cur->child)[index] == nullptr){
        (cur->child)[index] = new TRIE();
    }   
    return isPrefix(I+1, (cur->child)[index], phoneNumber);
}

bool getResult(){
    TRIE root;
    bool result = false;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> phoneNumbers[i];
    }
    sort(phoneNumbers, phoneNumbers+N);
    for(int i=0;i<N;i++){
        if(result) break;
        result = isPrefix(0, &root, phoneNumbers[i]);
    }
    return result;
}

int main(){
    cin >> T;
    for(int i=0;i<T;i++){
       if(getResult())
            cout<<"NO" << '\n';
        else
            cout<<"YES" <<'\n';
    }
    return 0;
}