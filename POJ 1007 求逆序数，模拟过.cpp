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
	int n,l;         //n�У�ÿ�г�l
	scanf("%d%d",&l,&n);
	for(int i = 0;i < n;i ++){     //������
		scanf("%s",a[i]);
		for(int j = 0;j < l-1;j ++)
			for(int k = j+1;k < l;k ++)   //ģ��Ƚ�
				if(a[i][j] > a[i][k])b[i] ++;
	}
	memcpy(c,b,n*sizeof(int));     
	qsort(c,n,sizeof(int),fun);    //��c������b���ҳ���Ӧ�±꣬���a
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < n;j ++)
			if(c[i] == b[j]){
				printf("%s\n",a[j]);
				b[j] = -1;             //�������������ֵΪ-1����ֹ�ظ�
				break;
			}
	return 0;
}