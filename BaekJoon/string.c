#include <stdio.h>
void strcat(char *d, char *s);
int strlen(char *d);
int strcmp(char *d, char *s);
void strcpy(char *d, char *s);

int main(){
    char str1[100];
    char str2[100];

    scanf("%s", str1);
    scanf("%s", str2);

    strcat(str1, str2);
    printf("%s\n", str1);
    printf("%d\n", strcmp(str1, str2));
    return 0;
}

int strlen(char *d){
    int i=0;
    while(d[i]){
        i++;
    }
    return i;
}

int strcmp(char *d, char *s){
    int i=0;
    while(*(d+i)){
        if(*(d+i)!=*(s+i)){
            break;
        }
        i++;
    }
    return *(d+i) - *(s+i);
}

void strcpy(char *d, char *s){
    int i=0;
    while(s[i]){
        d[i] = s[i];
        i++;
    }
    d[i]=s[i];
}

void strcat(char *d, char *s){
    int dlen = strlen(d);
    strcpy(d+dlen, s);
}