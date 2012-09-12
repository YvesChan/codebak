#include<cstdio>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		int m,n;
		scanf("%d%d",&m,&n);
		printf("Scenario #%d:\n",i);
		if(m & 1 && n & 1)printf("%d.41\n\n",m * n);
		else printf("%d.00\n\n",m * n);
	}
	return 0;
}