#include<stdio.h>
#include<stdlib.h>
int mycompare(const void *elem1,const void *elem2){
	int *p1,*p2;
	p1=(int *)elem1;
	p2=(int *)elem2;
	return (*p1%10)-(*p2%10);
}
const int num=8;
int main(){
	int a[num]={23,19,543,12,54,15,87,2};
	qsort(a,num,sizeof(int),mycompare);
	for(int i=0;i<num;i++){
		printf("a[%d]=%d\n",i,a[i]);
	}
}