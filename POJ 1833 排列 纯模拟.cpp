#include<cstdio>
#include<cstdlib>
int cmp(const void *elem1,const void *elem2){
	return *(int *)elem1 - *(int *)elem2;
}
int main()
{
	int m,n,k;
	scanf("%d",&m);
	while(m --){
		scanf("%d%d",&n,&k);
		int num[1100] = {0},i,j;
		for(int i = 0;i < n;i ++)
			scanf("%d",&num[i]);
		while(k){
			for(i = n - 1;i > 0;i --){
				if(num[i] < num[i-1])continue;         //��һ������ǰһ����С�����
				else {
					for(j = i;j < n;j ++){
						if(num[j] < num[i-1]){         //��[i,n-1]�������ҵ���num[i-1]�����С����������֮
							num[j - 1] ^= num[i - 1];
							num[i - 1] ^= num[j - 1];
							num[j - 1] ^= num[i - 1];
							break;
						}
					}
					if(j == n){                         //û�ҵ���num[i-1]�ͱ�β����
						num[n - 1] ^= num[i - 1];
						num[i - 1] ^= num[n - 1];
						num[n - 1] ^= num[i - 1];
					}
					qsort(num + i,n - i,sizeof(int),cmp);  //[i,n-1]����
					k --;
					break;
				}
			}
			if(i == 0){qsort(num,n,sizeof(int),cmp);k--;}  //�Ѿ����������У������´�С��������
		}
		for(int i = 0;i < n;i ++){
			if(i == n - 1){printf("%d\n",num[i]);break;}
			printf("%d ",num[i]);
		}
	}
	return 0;
}