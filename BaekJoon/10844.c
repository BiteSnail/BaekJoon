#include <stdio.h>
#define MODNUM 1000000000

int stair[105][10];

int main(void){
	int n;
	int result;
	scanf("%d", &n);

	for(int i=0;i<105;i++){
		for(int j=0;j<10;j++)
			stair[i][j]=0;
	}
	for(int i=1;i<10;i++)
		stair[1][i]=1;

	for(int i=2;i<=n;i++){
		stair[i][0]=stair[i-1][1]%MODNUM;
		for(int j=1;j<9;j++)
			stair[i][j]=(stair[i-1][j-1]+stair[i-1][j+1])%MODNUM;
		stair[i][9]=stair[i-1][8]%MODNUM;
	}
	result=0;
	for(int i=0;i<10;i++){
		result+=stair[n][i];
		result%=MODNUM;
	}
	printf("%d\n",result);
}