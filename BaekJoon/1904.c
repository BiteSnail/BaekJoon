#include <stdio.h>
#define MAX_LENGTH 1000001
int tile[MAX_LENGTH];

void SetTile(int n){
	if(tile[n-1]>0 && tile[n-2]){
		tile[n]=(tile[n-1]+tile[n-2])%15746;
	}
	else{
		SetTile(n-1);
		tile[n]=(tile[n-1]+tile[n-2])%15746;
	}
}

int main(void){
	int n;
	scanf("%d", &n);
	
	for(int i=1;i<MAX_LENGTH;i++){
		tile[i]=0;
	}
	tile[0]=tile[1]=1;
	SetTile(n);
	
	printf("%d\n",tile[n]);
	
}