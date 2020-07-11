#include<stdio.h>
#include<stdlib.h>

int *c=(int *)malloc(sizeof(int));

int main(){
c=(int *)malloc(sizeof(int));
c=4;
printf("%d",c);
return 0;
}
