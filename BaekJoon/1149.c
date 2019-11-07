#include <stdio.h>

int RGB[3][1001];
int MIN[3][1001];

int flag;
int result;

int min(int a, int b){
	if(a>b)
		return b;
	else 
		return a;
}

void dp(int n){
	if(MIN[0][n-1]==0){
		dp(n-1);
	}
	MIN[0][n]=min(MIN[1][n-1],MIN[2][n-1])+RGB[0][n];
	MIN[1][n]=min(MIN[0][n-1],MIN[2][n-1])+RGB[1][n];
	MIN[2][n]=min(MIN[0][n-1],MIN[1][n-1])+RGB[2][n];
}

int main(void){
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d", &RGB[0][i], &RGB[1][i], &RGB[2][i]);
		MIN[0][i]=MIN[1][i]=MIN[2][i]=0;
	}
	MIN[0][1]=RGB[0][1];
	MIN[1][1]=RGB[1][1];
	MIN[2][1]=RGB[2][1];

	dp(n);
	
	printf("%d\n",min(MIN[0][n],min(MIN[1][n],MIN[2][n])));

	return 0;
}