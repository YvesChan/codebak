#include<stdio.h>
#include<string.h>
int main()
{
	int num,sum=0;     
	int i,j;
	while(scanf("%d",&num)!=EOF&&num){     //关键判断条件！！
		char *color[100]={NULL};    //颜色分类数组。不要开太小！
		char tmp[20];
		int count[100]={0};        //分别统计每种颜色的次数
		for(i = 0;i < num;i ++){
			scanf("%s",&tmp);
			for(j = 0;j < sum;j ++){
				if(strcmp(tmp,color[j]) == 0){
					count[j] ++;break;        //颜色次数+1
				}
			}
			if(j == sum){
				color[sum] = new char[20];
				strcpy(color[sum],tmp);     //创建新颜色类
				sum ++;                 //颜色总数+1
			}
		}
		int t = 0,k = 0;
		for(i = 0;i < sum;i++)
			if(count[i] > t){t = count[i];k = i;}
		printf("%s\n",color[k]);
		sum = 0;
	}
}