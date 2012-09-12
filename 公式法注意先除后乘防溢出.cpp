#include<stdio.h>
int main()
{
	int n,sum=0;
	while(scanf("%d",&n)!=EOF){
		if(n % 2 == 0)sum = n / 2 * (n+1);  //公式法！先除后乘，防止中途溢出
		else sum = (n + 1) / 2 * n;
		printf("%d\n\n",sum);
		sum = 0;
	}
}
