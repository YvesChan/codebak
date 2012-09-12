#include<cstdio>
const int MAX = 10050;
int number[10050] = {1,1,0};
int prime_list[2000];
int ans[MAX];
int main()
{
	int i,j,k,sum = 0;
	for(i = 2;i < 105;i ++)
		if(number[i] == 0)
			for(j = i * i;j < 10030;j += i)number[j] = 1;
	for(i = 2,k = 0;i < 10030;i ++)
		if(number[i] == 0){prime_list[k] = i;k ++;}      //prime number list
	for(i = 0;prime_list[i] < 10030 && prime_list[i] > 0;i ++){     //here forget the rest 0 are also below 10030 = =
		for(j = i;sum < 10030;j ++){
			ans[sum] ++;
			sum += prime_list[j];
		}
		sum = 0;
	}
	while(scanf("%d",&i) && i)
		printf("%d\n",ans[i]);
	return 0;
}
			