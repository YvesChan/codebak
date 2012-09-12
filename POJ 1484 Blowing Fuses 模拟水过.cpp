#include<cstdio>
int main()
{
	int n,m,c,i,count = 1;
	while(scanf("%d%d%d",&n,&m,&c) &&  n){
		int dev[21]={0},flag[21]={0},max = 0,sum = 0;
		for(i = 1;i <= n;i ++)
			scanf("%d",&dev[i]);
		while(m --){
			scanf("%d",&i);
			if(!flag[i]){
				flag[i] = 1;
				sum += dev[i];
			}
			else {flag[i] = 0;sum -= dev[i];}
			if(sum > max)max = sum;
		}
		printf("Sequence %d\n",count);
		if(max > c)printf("Fuse was blown.\n\n");
		else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",max);
		count ++;
	}
	return 0;
}
