#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> s[201];

int main(){
    int n;
    int age;
    char buf[256];

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d %s", &age, buf);
        s[age].push_back(buf);
    }

    for(int i=1;i<=200;i++){
        if(s[i].size()>0){
            for(vector<string>::iterator iter=s[i].begin(); iter != s[i].end();iter++){
                printf("%d %s\n", i, iter->c_str());
            }
        }
    }

    return 0;
}