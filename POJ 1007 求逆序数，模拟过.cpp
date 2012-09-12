#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fun(const void *elem1,const void *elem2){
	int *p1,*p2;
	p1=(int *)elem1;
	p2=(int *)elem2;
	return *p1 - *p2;
}
int main()
{
	char a[100][51]={NULL};
	int b[100]={0};
	int c[100]={0};
	int n,l;         //n行，每行长l
	scanf("%d%d",&l,&n);
	for(int i = 0;i < n;i ++){     //控制行
		scanf("%s",a[i]);
		for(int j = 0;j < l-1;j ++)
			for(int k = j+1;k < l;k ++)   //模拟比较
				if(a[i][j] > a[i][k])b[i] ++;
	}
	memcpy(c,b,n*sizeof(int));     
	qsort(c,n,sizeof(int),fun);    //将c排序，在b中找出对应下标，输出a
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < n;j ++)
			if(c[i] == b[j]){
				printf("%s\n",a[j]);
				b[j] = -1;             //已输出的重置数值为-1，防止重复
				break;
			}
	return 0;
}