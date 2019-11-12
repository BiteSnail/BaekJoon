#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp(string &a, string &b){
    if(a.size()<b.size())
        return true;
    else if(a.size()==b.size()){
        if(a.compare(b)<0) return true;
        else return false; 
    }
    else return false;
}

int main(){
    int n;
    vector<string> s;
    char buf[256];
    scanf("%d", &n);
    
    for(int i=0;i<n;i++){
        scanf("%s", buf);
        s.push_back(buf);
    }

    sort(s.begin(),s.end(), comp);
    s.erase(unique(s.begin(), s.end()),s.end());

    for(vector<string>::iterator iter=s.begin(); iter!=s.end();iter++){
        printf("%s\n",iter->c_str());
    }

    return 0;
}