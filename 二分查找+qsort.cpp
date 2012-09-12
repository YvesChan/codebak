#include<cstdio>
#include<cstdlib>
int cmp(const void *elem1,const void *elem2)
{
	int *p1 = (int*)elem1;
	int *p2 = (int*)elem2;
	return *p1 - *p2;
}
int binsearch(int p[],int n,int k)       //���ֲ���
{
	int low = 0,high = n - 1,mid;    //��ʼ�������� 0 �� n-1
		if(p[0] == k)return 0;
		while(low <= high){
			mid = (low + high) / 2;       //���������low + (high - low) / 2,��ֹ���
			if(p[mid] == k)return mid;
			if(p[mid] < k)low = mid + 1;  //�任��������
			else high = mid - 1;
		}
		return -1;
}

int main()
{
	int n,m,t,a[100001];
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i ++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmp);
	while(m--){
		scanf("%d",&t);
		printf("%d\n",1 + binsearch(a,n,t));
	}
	return 0;
}