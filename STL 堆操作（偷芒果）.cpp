#include<cstdio>
#include<algorithm>
using namespace std;     //Ҫ��std
int main()
{
	int n,a[100001]={0},t=0,h,sum=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a[t],&h);
		push_heap(&a[0],&a[t+1]);     //ע��ڶ����������±꣡�ޱȽϺ�����Ĭ������
		if(h <= 23){
			sum += a[0];
			pop_heap(&a[0],&a[t+1]);
		}
		else t++;
	}
	printf("%d\n",sum);
	return 0;
}
