#include <stdio.h>

unsigned long long donoban[200];

void DON(int n){
	if(donoban[n-1]>0 && donoban[n-4]>0)
		donoban[n]=donoban[n-1]+donoban[n-5];
	else{
		if(n>5)
			DON(n-1);
		donoban[n]=donoban[n-1]+donoban[n-5];
	}
}

int main(void){
	int n;
	int t;
	for(int i=0;i<200;i++){
		donoban[i]=0;
	}
	donoban[1]=donoban[2]=donoban[3]=1;
	donoban[4]=donoban[5]=2;
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		if(n>5)
			DON(n);
		printf("%llu\n",donoban[n]);
	}
	return 0;
}