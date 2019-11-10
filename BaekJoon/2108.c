#include <stdio.h>

int num[8001];

int main(void){
	int total=0;
	double aver;
	int mv=0;
	int min=9999, max=-9999;
	int n;
	int temp;
	int flag;

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
	temp=0;
	for(int i=min+4000; i<=max+4000;i++){
		temp+=num[i];
		if(temp>n/2){
			printf("%d\n",i-4000);
			break;
		}
	}
	flag=0;
	for(int i=mv+4001;i<=max+4000;i++){
		if(num[i]==num[mv+4000]){
			printf("%d\n",i-4000);
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("%d\n",mv);
	
	printf("%d\n",max-min);
	return 0;
}