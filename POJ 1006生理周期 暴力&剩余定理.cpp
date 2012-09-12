#include<cstdio>
int main()
{
	int p,e,i,d,count = 1;
	while(scanf("%d%d%d%d",&p,&e,&i,&d) && p != -1){
		int res = 0;
		for(int k = 0;k < 700;k ++){
			i %= 33;           //这里wa了一次。囧~
			res = i + 33 * k;     //取最大的除数33，效率比较高
			if(!((res - e) % 28) && !((res - p) % 23) && res > d){
				printf("Case %d: the next triple peak occurs in %d days.\n",count,res - d);
				count ++;
				break;
			}
		}
	}
	return 0;
}