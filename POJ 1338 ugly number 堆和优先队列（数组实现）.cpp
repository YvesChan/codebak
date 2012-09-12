#include<cstdio>
int u[1510];
int main()
{
	int t2,t3,t5,i,p2,p3,p5;
	u[1] = 1;
	p2 = p3= p5 = 1;
	for(i = 2;i < 1501;i ++){
		t2 = u[p2] * 2;
		t3 = u[p3] * 3;
		t5 = u[p5] * 5;
		u[i] = t2 < t3 ? (t2 < t5 ? t2 : t5) : (t3 < t5 ? t3 : t5);     //返回最小值
		if(u[i] == t2)p2 ++;
		if(u[i] == t3)p3 ++;
		if(u[i] == t5)p5 ++;              //最小值下标+1
	}
	int n;
	while(scanf("%d",&n) && n)
		printf("%d\n",u[n]);
	return 0;
}

//其实是可以用堆来解决。用1*2，1*3,1*5，然后入堆，弹出最小值再乘2,3,5，再入堆，再弹，循环1500次