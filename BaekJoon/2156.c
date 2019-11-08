#include <stdio.h>

int wine[10001];
int mount[2][10001];

int comp1(int a,int b){
	return a > b ? a : b;
}

int main(void){
	int n;
	int re;
	for(int i=0;i<10001;i++){
		mount[0][i]=mount[1][i]=0;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&wine[i]);
	}
	
	mount[0][1]=wine[1];
	for(int i=2;i<=n;i++){
		mount[0][i]=comp1(mount[0][i-2],mount[1][i-2])+wine[i];
		if(i>2)
			mount[0][i]=comp1(mount[0][i], comp1(mount[0][i-3], mount[0][i-3])+wine[i]);
		mount[1][i]=mount[0][i-1]+wine[i];
	}
	
	for(int i=1;i<=n;i++){
		printf("[%d %d]\n",mount[0][i], mount[1][i]);
	}

	re=comp1(mount[0][n], mount[1][n]);
	re=comp1(re, comp1(mount[0][n-1],mount[1][n-1]));
	printf("%d\n",re);	

}