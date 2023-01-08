#include <iostream>
#include <string>
#include <stack>

using namespace std;

string infix;
stack<char> operStack;

inline bool isAlpha(const char c){
    return 'A' <= c && c <= 'Z';
}

int isp(const char oper){
    switch(oper){
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '(':
        return 0;
        default:
        return -1;
    }    
}

int icp(const char oper){
    switch(oper){
        case '+':
        case '-':
        case '*':
        case '/':
        return isp(oper);
        case '(':
        return 3;
        default:
        return -1;
    }
}

int main(){
    cin >> infix;
    for(auto &c:infix){
        if(isAlpha(c))
            cout<<c;
        else if(c==')'){
            while(operStack.top()!='('){
                cout<<operStack.top();
                operStack.pop();
            }
            operStack.pop();
        }
        else{
            while(!operStack.empty() && isp(operStack.top()) >= icp(c)){
                cout<<operStack.top();
                operStack.pop();
            }
            operStack.push(c);
        }
    }
    while(!operStack.empty()){
        cout<<operStack.top();
        operStack.pop();
    }
    
    return 0;
}