#include<stdio.h>
#include<string.h>
int main()
{
	int num,sum=0;     
	int i,j;
	while(scanf("%d",&num)!=EOF&&num){     //�ؼ��ж���������
		char *color[100]={NULL};    //��ɫ�������顣��Ҫ��̫С��
		char tmp[20];
		int count[100]={0};        //�ֱ�ͳ��ÿ����ɫ�Ĵ���
		for(i = 0;i < num;i ++){
			scanf("%s",&tmp);
			for(j = 0;j < sum;j ++){
				if(strcmp(tmp,color[j]) == 0){
					count[j] ++;break;        //��ɫ����+1
				}
			}
			if(j == sum){
				color[sum] = new char[20];
				strcpy(color[sum],tmp);     //��������ɫ��
				sum ++;                 //��ɫ����+1
			}
		}
		int t = 0,k = 0;
		for(i = 0;i < sum;i++)
			if(count[i] > t){t = count[i];k = i;}
		printf("%s\n",color[k]);
		sum = 0;
	}
}