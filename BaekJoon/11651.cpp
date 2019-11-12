#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _pos{
    int x;
    int y;
}POS;

POS p[100000];

bool comp(POS a, POS b){
    if(a.y < b.y)
        return true;
    else if(a.y==b.y){
        if(a.x<b.x)
            return true;
        else 
            return false;
    }
    else
    {
        return false;
    }
}

int main(void){
    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    sort(p, p+n, comp);

    for(int i=0;i<n;i++){
        printf("%d %d\n", p[i].x, p[i].y);
    }
}