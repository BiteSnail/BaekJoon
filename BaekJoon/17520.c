#include <stdio.h>

int main(void){
	int n;
	scanf("%d", &n);
	int a=1;
	n=(n+1)/2;
	for(int i=1;i<=n;i++){
		a*=2;
		a%=16769023;
	}
	printf("%d\n", a);
	
	
}