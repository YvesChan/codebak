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
				if(num[i] < num[i-1])continue;         //后一个数比前一个数小则继续
				else {
					for(j = i;j < n;j ++){
						if(num[j] < num[i-1]){         //在[i,n-1]的区间找到比num[i-1]大的最小的数，交换之
							num[j - 1] ^= num[i - 1];
							num[i - 1] ^= num[j - 1];
							num[j - 1] ^= num[i - 1];
							break;
						}
					}
					if(j == n){                         //没找到则num[i-1]和表尾交换
						num[n - 1] ^= num[i - 1];
						num[i - 1] ^= num[n - 1];
						num[n - 1] ^= num[i - 1];
					}
					qsort(num + i,n - i,sizeof(int),cmp);  //[i,n-1]排序
					k --;
					break;
				}
			}
			if(i == 0){qsort(num,n,sizeof(int),cmp);k--;}  //已经是最大的排列，则重新从小到大排列
		}
		for(int i = 0;i < n;i ++){
			if(i == n - 1){printf("%d\n",num[i]);break;}
			printf("%d ",num[i]);
		}
	}
	return 0;
}