#include<cstdio>
#include<cmath>
int main()
{
	int a[16][3]={0},b[3]={0};
	for(int i = 0;i < 16;i ++)
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	while(scanf("%d%d%d",&b[0],&b[1],&b[2])){
		if(b[0] == -1 && b[1] == -1 && b[2] == -1)
			break;
		int t = 0,d = 0,min = 10000000;
		for(int i = 0;i < 16;i ++){
			d = sqrt((a[i][0] - b[0]) * (a[i][0] - b[0]) + (a[i][1] - b[1]) *(a[i][1] - b[1])
				+ (a[i][2] - b[2]) * (a[i][2] - b[2]) + 0.0);
			if(d < min){
				min = d;
				t = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",b[0],b[1],b[2],a[t][0],a[t][1],a[t][2]);
	}
	return 0;
}