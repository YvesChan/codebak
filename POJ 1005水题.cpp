#include<stdio.h>
int main()
{
	int n,z;
	double x,y;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lf %lf",&x,&y);
		z = 3.1415 * (x * x + y * y) / 100 + 1;
		printf("Property %d: This property will begin eroding in year %d.\n",i,z);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}


//喵的一开始就想着打表，其实换个思路可以很简单，囧~总是想复杂了