#include<cstdio>
#include<cmath>
int f(int x,int j)     //��j������x����10����
{
	int i = 0,t = 0;
	while(x){
		if(x % 10 >= j)return -1;     //��ʼû�п��ǵ������Ҫ������ = =
		t += (x % 10) * pow(j+0.0,i+0.0);
		x /= 10;
		i++;
	}
	return t;
}

int main()
{
	int n,p,q,r,i;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d",&p,&q,&r);
		for(i = 2;i <= 16;i ++)
			if(f(p,i) * f(q,i) == f(r,i)){printf("%d\n",i);break;}
		if(i == 17)printf("0\n");
	}
	return 0;
}
