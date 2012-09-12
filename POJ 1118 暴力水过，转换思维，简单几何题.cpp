/*一开始就想着从n个点取2个求出k，b，然后就其他点代入看是否共线，怎么没有想到直接选一个点，然后比较和其
点的斜率呢？？果然还是欠经验。。。*/

#include<cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)&&n){
		int a[701][2]={0},tmp=0,max=0,x,y;
		for(int i = 0;i < n;i ++)
			scanf("%d %d",&a[i][0],&a[i][1]);
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j ++){          //先用两个点确定一条直线，再看第三个点是否在其上
				for(int k = j+1;k < n;k ++){
					x = (a[i][1] - a[j][1]) * (a[i][0] - a[k][0]);    //转换一下，用乘法可以避免float的问题
					y = (a[i][0] - a[j][0]) * (a[i][1] - a[k][1]);
					if(x == y)tmp++;
				}
				max = tmp>max ? tmp : max;
				tmp = 0;
			}
			printf("%d\n",max+2);
	}
	return 0;
}
