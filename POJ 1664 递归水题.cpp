#include<cstdio>
int f(int a,int b)
{
	if(b == 1 || a == 0)return 1;     //注意a为0的情况
	if(b == 2)return 1 + a / 2;    //这里优化了一下 = =
	if(a < b)return f(a,a);          //这里wa了一次，无语 = =
	return f(a,b - 1) + f(a - b,b);    //分两种情况，有空盘和没有空盘的
}
int main()
{
	int n,x,y;
	scanf("%d",&n);
	while(n --){
		scanf("%d%d",&x,&y);
		printf("%d\n",f(x,y));
	}
	return 0;
}