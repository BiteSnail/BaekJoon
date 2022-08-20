#include <iostream>
#include <string>

using namespace std;

bool is_vowel(const char c){
    return c == 'a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='O' || c=='o' || c=='u' || c=='U';
}

int main(){
    string str;
    int cnt;
    while(getline(cin, str), str!="#"){
        cnt = 0;
        for(int i=0;i<str.size();i++){
            cnt += is_vowel(str[i]);
        }
        cout<< cnt << '\n';
    }

    return 0;
}