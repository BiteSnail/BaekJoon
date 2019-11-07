#include <stdio.h>
#include <string.h>

int regi(char c[]){
	if(strcmp(c,"black")==0)
		return 0;
	else if(strcmp(c,"brown")==0)
		return 1;
	else if(strcmp(c,"red")==0)
		return 2;
	else if(strcmp(c,"orange")==0)
		return 3;
	else if(strcmp(c,"yellow")==0)
		return 4;
	else if(strcmp(c,"green")==0)
		return 5;
	else if(strcmp(c,"blue")==0)
		return 6;
	else if(strcmp(c,"violet")==0)
		return 7;
	else if(strcmp(c,"grey")==0)
		return 8;
	else
		return 9;
}

int main(void){
	char color[20];
	long long n=0;
	scanf("%s",color);
	n=regi(color);
	n*=10;
	scanf("%s",color);
	n+=regi(color);
	scanf("%s",color);
	for(int i=0;i<regi(color);i++){
		n*=10;
	}

	printf("%lld\n", n);
	return 0;
}