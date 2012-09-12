#include<stdio.h>
int main()
{
	double n[300]={0};
	for(int i = 2;i <= 300;i++){
		n[i-1] = n[i-2] + 1.0 / i;   //原先是1 / i,因为int除int得到还是int，所以结果总是0，必须用1.0！
		if(n[i-1] > 5.20)break;
	}
	double c;
	while(scanf("%lf",&c)&&c){
		for(int i = 1;i < 300;i++)
			if(n[i] > c){
				printf("%d card(s)\n",i);
				break;
			}
	}
	return 0;
}
