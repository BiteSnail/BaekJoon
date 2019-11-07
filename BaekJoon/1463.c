#include <stdio.h>
#define MAX_NUM 1000001

int count[MAX_NUM];

int recursive(int n){
	if(count[n]>0) return count[n];

	count[n]=recursive(n-1)+1;
	
	if(n%2==0){
		if(count[n]-1>recursive(n/2))
			count[n]=count[n/2]+1;
	}
	if(n%3==0){
		if(count[n]-1>recursive(n/3))
			count[n]=count[n/3]+1;
	}
	
	return count[n];
}
int main(void){
	int n;
	int result;
	scanf("%d",&n);
	count[1]=1;
	result=recursive(n);
	
	printf("%d\n",result-1);
}