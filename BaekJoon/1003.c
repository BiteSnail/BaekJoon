#include <stdio.h>

unsigned long long fibo0[50];
unsigned long long fibo1[50];
int fiboc[50];

void fibo(int n){
	if(fiboc[n-1] && fiboc[n-2]){
		fibo0[n]=fibo0[n-1]+fibo0[n-2];
		fibo1[n]=fibo1[n-1]+fibo1[n-2];
		fiboc[n]=1;
	}
	else{
		if(n>2)
			fibo(n-1);
		fibo0[n]=fibo0[n-1]+fibo0[n-2];
		fibo1[n]=fibo1[n-1]+fibo1[n-2];
		fiboc[n]=1;
	}
}

int main(void){
	int n;
	int l;
	for(int i=0;i<50;i++){
		fibo0[i]=fibo1[i]=fiboc[i]=0;
	}
	fibo0[0]=fiboc[0]=1;
	fibo1[1]=fiboc[1]=1;
	fibo0[2]=fibo1[2]=fiboc[2]=1;
	scanf("%d", &l);
	for(int i=0;i<l;i++){
		scanf("%d", &n);
		if(n>2)
			fibo(n);
		printf("%d %d\n",fibo0[n], fibo1[n]);

	}
}