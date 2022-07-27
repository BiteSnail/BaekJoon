#include <iostream>

using namespace std;

inline int get_next(bool ascending){
    return ascending ? 1 : -1;
}

void print_gugu(int n1, int n2){
    bool ascending = n1 < n2;
    int next = get_next(ascending);

    for(int i = 1; i<=9;i++){
        for(int j = n1; j != n2; j += next){
            printf("%d * %d = %2d   ",j, i, j*i);
        }
        printf("%d * %d = %2d\n",n2, i, n2*i);
    }
}

bool is_in(int n, int s, int e){
    return n >= s && n <= e;
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    while(!(is_in(n1, 2, 9) && is_in(n2, 2, 9))){
        cout<<"INPUT ERROR!\n";
        cin >> n1 >> n2;
    }
    print_gugu(n1, n2);
    
    return 0;
}