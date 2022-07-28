#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int sum = 0;
    int cur_wood_amount=0;
    cin >> str;
    for(int i=0;i<str.size();i++){
        if(str[i]==')'){
            cur_wood_amount--;
            sum += (str[i-1]=='(') ? cur_wood_amount : 1;
        }
        else{
            cur_wood_amount++;
        }
    }

    cout<< sum;

    return 0;
}