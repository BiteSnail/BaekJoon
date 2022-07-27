#include <iostream>
#include <string>

using namespace std;

char decode[128];

int main(){
    string key;
    string encrpyt_str;
    getline(cin, key);
    getline(cin, encrpyt_str);

    for(int i=0;i<key.size();i++){
        decode['a' + i] = 'a'+key[i]-'a';
        decode['A' + i] = 'A'+key[i]-'a';
    }

    for(int i=0;i<encrpyt_str.size();i++){
        if(encrpyt_str[i]==' '){
            printf(" ");
        }
        else{
            printf("%c",decode[encrpyt_str[i]]);
        }
    }
    return 0;
}