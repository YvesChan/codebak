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
		u[i] = t2 < t3 ? (t2 < t5 ? t2 : t5) : (t3 < t5 ? t3 : t5);     //������Сֵ
		if(u[i] == t2)p2 ++;
		if(u[i] == t3)p3 ++;
		if(u[i] == t5)p5 ++;              //��Сֵ�±�+1
	}
	int n;
	while(scanf("%d",&n) && n)
		printf("%d\n",u[n]);
	return 0;
}

//��ʵ�ǿ����ö����������1*2��1*3,1*5��Ȼ����ѣ�������Сֵ�ٳ�2,3,5������ѣ��ٵ���ѭ��1500��