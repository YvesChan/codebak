#include<cstdio>
int f(int a,int b)
{
	if(b == 1 || a == 0)return 1;     //ע��aΪ0�����
	if(b == 2)return 1 + a / 2;    //�����Ż���һ�� = =
	if(a < b)return f(a,a);          //����wa��һ�Σ����� = =
	return f(a,b - 1) + f(a - b,b);    //������������п��̺�û�п��̵�
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