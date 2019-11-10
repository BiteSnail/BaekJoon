#include <stdio.h>

int wine[10001];
int mount[10001];

int comp1(int a,int b){
	return a > b ? a : b;
}

int solve(int n){
	if(n<1) return 0;

	if(mount[n]>0) return mount[n];

	mount[n]=comp1(solve(n-1), wine[n]+solve(n-2));
	mount[n]=comp1(mount[n],wine[n]+wine[n-1]+solve(n-3));

	return mount[n];
	
}

int main(void){
	int n;
	int re;
	for(int i=0;i<10001;i++){
		mount[i]=0;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&wine[i]);
	}
	mount[1]=wine[1];

	re=solve(n);
	
	printf("%d\n",re);	

}