#include <stdio.h>
#include <string.h>

int stairpoint[301];
int memo[2][301];

int comp(int a, int b){
	return a > b ? a : b;
}

void solve(int n){
	int max;
	if(n>2){
		solve(n-1);
	}
	max=comp(memo[1][n-2],memo[0][n-2]);
	memo[0][n]=stairpoint[n]+max;
	memo[1][n]=stairpoint[n]+memo[0][n-1];
	//printf("%d : %d %d\n",n, memo[0][n],memo[1][n]);
}

int main(void){
	int n;
	memset(memo, 0,sizeof(memo));
	scanf("%d", &n);

	for(int i=1;i<=n;i++){
		scanf("%d", &stairpoint[i]);
	}
	memo[0][1]=stairpoint[1];
	memo[0][2]=stairpoint[2];
	//printf("%d : %d %d \n",0, memo[0][0], memo[1][0]);
	//printf("%d : %d %d \n",1, memo[0][1], memo[1][1]);
	solve(n);

	printf("%d\n",comp(memo[0][n],memo[1][n]));
}