#include <stdio.h>

int num[8001];

int main(void){
	int total=0;
	double aver;
	int mv=0;
	int min=9999, max=-9999;
	int n;
	int temp;

	for(int i=0;i<8001;i++){
		num[i]=0;
	}

	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &temp);
		num[temp+4000]++;
		if(temp<min) min=temp;
		if(temp>max) max=temp;
		total+=temp;
		if(num[temp+4000]>num[mv+4000])
			mv=temp;
		else if(num[temp+4000]==num[mv+4000])
			if(temp<mv) mv=temp;
	}
	aver=(double)total / (double)n;

	printf("%.0f\n",aver);
	for(int i=min; i<=max;i++){
		
	}

	
	printf("%d\n",max-min);

}