#include <stdio.h>

int tri[501][501];

int comp(int a, int b){
	return a > b ? a : b;
}

int main(void){
	int n;
	int i, j;
	int result=0;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		for(j=0;j<i+1;j++)
			scanf("%d", &tri[i][j]);
	}
	
	for(i=0;i<n-1;i++){
		tri[i+1][0]+=tri[i][0];
		for(j=0;j<i;j++){
			tri[i+1][j+1]+=comp(tri[i][j],tri[i][j+1]);
		}
		tri[i+1][i+1]+=tri[i][i];
	}

	result=tri[n-1][0];
	for(int i=1;i<n;i++){
		result=comp(tri[n-1][i], result);
	}

	printf("%d\n",result);
	return 0;
}