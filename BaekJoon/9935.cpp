#include <iostream>
#include <string>

using namespace std;
string inputStr;
string outputStr;

int index;
const string noReamin = "FRULA";

bool canExplosion(const string & explosionStr){
    if(outputStr.size() >= explosionStr.size())
        return outputStr.substr(outputStr.size()-explosionStr.size())==explosionStr;
    return false;
}

int main(){
    string explosionStr;
    cin >> inputStr;
    cin >> explosionStr;
    for(auto &c:inputStr){
        outputStr.push_back(c);
        if(c==explosionStr.back() && canExplosion(explosionStr)){
            for(int i=0;i<explosionStr.size();i++)
                outputStr.pop_back();
        }
        
    }
    if(outputStr.empty()){
        cout<<noReamin;
    }
    else{
        cout<<outputStr;
    }
    return 0;
}