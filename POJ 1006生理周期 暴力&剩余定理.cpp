#include<cstdio>
int main()
{
	int p,e,i,d,count = 1;
	while(scanf("%d%d%d%d",&p,&e,&i,&d) && p != -1){
		int res = 0;
		for(int k = 0;k < 700;k ++){
			i %= 33;           //����wa��һ�Ρ���~
			res = i + 33 * k;     //ȡ���ĳ���33��Ч�ʱȽϸ�
			if(!((res - e) % 28) && !((res - p) % 23) && res > d){
				printf("Case %d: the next triple peak occurs in %d days.\n",count,res - d);
				count ++;
				break;
			}
		}
	}
	return 0;
}