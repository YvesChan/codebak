#include<cstdio>
#include<cmath>
int main()
{
	int n,flag = 0;
	while(scanf("%d",&n) && n){
		if(!flag){printf("PERFECTION OUTPUT\n");flag = 1;}
		printf("%5d  ",n);      //�������
		int sum = 0;
		for(int i = 2;i <= sqrt(n+0.0);i ++)    //���öԳ������
			if(n % i == 0){
				if(i == sqrt(n+0.0))sum += i;
				else sum += i + n / i;
			}
		if(n != 1)sum++;       //�ر�ע��1��sumӦ����0������wa��һ��
		if(sum == n)printf("PERFECT\n");
		if(sum < n)printf("DEFICIENT\n");
		if(sum > n)printf("ABUNDANT\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
		