#include<cstdio>
int f(int a,int b)            //return the last three number
{
	a %= 1000;
	if(b == 1)return a;
	if(b == 2)return (a * a) % 1000;
	int t = f(a,b / 2);
	if(b > 2 && b & 1)return (t * t * a) % 1000;      //if b is odd number
	return (t * t) % 1000;
}
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n) && m)
		printf("%d\n",f(m,n));
	return 0;
}





/*
#include<cstdio>
int main()
{
	int a,b,sum;
	while(scanf("%d%d",&a,&b) && a){
		sum = a;
		for(int i = 1;i < b;i ++){
			sum *= a;
			if(sum >= 1000)sum %= 1000;
		}
		printf("%d\n",sum);
	}
	return 0;
}

*/