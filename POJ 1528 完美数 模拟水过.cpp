#include<cstdio>
#include<cmath>
int main()
{
	int n,flag = 0;
	while(scanf("%d",&n) && n){
		if(!flag){printf("PERFECTION OUTPUT\n");flag = 1;}
		printf("%5d  ",n);      //输出长度
		int sum = 0;
		for(int i = 2;i <= sqrt(n+0.0);i ++)    //利用对称性求和
			if(n % i == 0){
				if(i == sqrt(n+0.0))sum += i;
				else sum += i + n / i;
			}
		if(n != 1)sum++;       //特别注意1的sum应该是0，这里wa了一次
		if(sum == n)printf("PERFECT\n");
		if(sum < n)printf("DEFICIENT\n");
		if(sum > n)printf("ABUNDANT\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
		