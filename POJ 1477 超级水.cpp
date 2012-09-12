#include<cstdio>
int main()
{
	int n,count = 1;
	while(scanf("%d",&n) && n){
		int a[51]={0},sum = 0,mov = 0;
		for(int i = 0;i < n;i ++){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		for(int i = 0;i < n;i ++)
			if(a[i] > sum / n)mov += a[i] - sum / n;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",count,mov);
		count ++;
	}
	return 0;
}