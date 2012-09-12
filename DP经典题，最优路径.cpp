#include<stdio.h>
int n = 0;
int num[110][110]={0},t[110][110]={0};
int max(int a,int b)           //递归
{
	if(a == n)return num[a][b];
	if(t[a+1][b] == 0)t[a+1][b] = max(a+1,b);            //未算过最优路径则记录
	if(t[a+1][b+1] == 0)t[a+1][b+1] = max(a+1,b+1);
	if(t[a+1][b] < t[a+1][b+1])return num[a][b] + t[a+1][b+1];
	return num[a][b] + t[a+1][b];
}
		
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= i;j++)
			scanf("%d",&num[i][j]);
	printf("%d",max(1,1));
}
