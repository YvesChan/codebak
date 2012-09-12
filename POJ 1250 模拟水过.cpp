#include<cstdio>
#include<cstring>
int main()
{

	int n,t,i,j,sum=0;
	while(scanf("%d",&n) && n){
		char a[22]={'\0'};
		char c[5000]={'\0'};
		scanf("%s",c);
		t = strlen(c);
		for(i = 0;i < t;i ++){
			for(j = 0;j < n;j ++)
				if(a[j] == c[i]){a[j] = '\0';break;}      //先检查是否有相同的元素，有则重置为0
			if(j < n)continue;                            //忽略下面操作，进入下一个C[i]对比
			for(j = 0;j < n;j ++)
				if(a[j] == '\0'){a[j] = c[i];break;}      //有空位则写入
			if(j == n)sum++;                              //无则人数+1
		}
		if(!sum)printf("All customers tanned successfully.\n");
		else printf("%d customer(s) walked away.\n",sum/2);
		sum = 0;
	}
	return 0;
}