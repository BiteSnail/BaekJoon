#include <stdio.h>

void X(int m, int n){
	//printf("%d %d %d\n", m, n, m%n);
	if(m>0){
		X(m/n,n);

		if(m%n>=10)
			printf("%c",'A'+m%n-10);
		else
			printf("%d",m%n);
	}
}

int main(void){
	int m, n;
	scanf("%d %d", &m, &n);
	if(m>0)
		X(m, n);
	else
		printf("0");
	printf("\n");

}