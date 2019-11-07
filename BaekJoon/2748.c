#include <stdio.h>

unsigned long long fnum[100];

 void fibo(int n){
	if(fnum[n-1]>0 && fnum[n-2]>0)
		fnum[n]=fnum[n-1]+fnum[n-2];
	else{
		fibo(n-1);
		fnum[n]=fnum[n-1]+fnum[n-2];
	}
}

int main(void){
	int n;
	for(int i=0;i<100;i++){
		fnum[i]=0;
	}
	fnum[0]=0;
	fnum[1]=1;
	fnum[2]=1;
	scanf("%d", &n);
	if(n>2)
		fibo(n);

	printf("%llu\n",fnum[n]);
	return 0;
}