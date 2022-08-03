#include <iostream>
#include <string>

using namespace std;

int Qs[50];

int intlen(int i){
    int len = 0;
    while(i){
        i/=10;
        len++;
    }
    return len;
}

string find_answer(string L, string R, int Q){
    string answer;
    int len;
    int l, r;

    for(int i=0;i<Q;i++){
        string Qi = to_string(Qs[i]);
        l = r = 0;
        for(int j=0;j<Qi.size();j++){
            if(L[l] > R[r]){
                if(Qs[j] <= R[r] || Qs[j]>=L[l]){
                    
                }    
            }
            else{
                if(Qs[j] <= R[r] && Qs[j] >= L[l]){

                }
            }
        }
    }
    return answer;
}

int main(void)
{
    int T;
    int L, R;
    int Q;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        scanf("%d %d %d", &L, &R, &Q);
        for(int i=0;i<Q;i++){
            scanf("%d", &Qs[i]);
        }
        printf("#%d %s\n",t, find_answer(to_string(L),to_string(R),Q).c_str());
    }
    return 0;
}