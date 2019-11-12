#include <stdio.h>

typedef struct _pos{
    int x;
    int y;
}POS;

int comp1(POS a, POS b){
    if(a.x > b.x)
        return 1;
    else if(a.x==b.x){
        if(a.y>b.y)
            return 1;
        else
            return -1;
    }
    else
        return -1;
    
}

int getPivot(POS p[], int left, int right){
    POS temp;
    int pivot=right;
    int j=left;

    for(int i=left;i<right;i++){
        if(comp1(p[pivot],p[i])>0){
            temp=p[j]; p[j]=p[i]; p[i]=temp;
            j++;
        }
    }
    temp=p[j]; p[j]=p[pivot]; p[pivot]=temp;
    pivot=j;
    return pivot;
}

void QSORT(POS p[], int left, int right){
    int pivot;
    if(left>right)
        return;
    else{
        pivot=getPivot(p, left, right);
        QSORT(p,left, pivot-1);
        QSORT(p, pivot+1, right);
    }
}

int main(void){
    int n;
    POS p[100000];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    QSORT(p, 0, n-1);

    for(int i=0;i<n;i++){
        printf("%d %d\n",p[i].x, p[i].y);
    }
}