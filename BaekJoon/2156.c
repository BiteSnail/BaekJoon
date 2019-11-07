#include <stdio.h>

int wine[10001];
int mount[10001];

int comp1(int a,int b){
	return a > b ? a : b;
}

int solve(int n, int flag){
	if(n<1) return 0;

	if(mount[n]>0) return mount[n];
	else{
		solve(n-1,1);
		//printf("mount[%d]: %d -> ",n, mount[n]);
		if(flag<2){
			mount[n]=comp1(mount[n], wine[n]+solve(n-1, flag+1));
			//printf("%d",mount[n]);
		}
		mount[n]=comp1(mount[n], wine[n]+solve(n-2, 1));
		//printf("%d -> ",mount[n]);
		
		//printf("\n");
	}

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
	
	for(int i=1;i<=n;i++)
		printf("%d: %d\n",i, mount[i]);
	re=solve(n, 1);
	for(int i=1;i<=n;i++)
		printf("%d: %d\n",i, mount[i]);
	printf("%d\n",re);	

}