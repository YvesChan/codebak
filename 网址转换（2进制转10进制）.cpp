#include<stdio.h>
#include<cmath>
int main()
{
	int n;
	char bin[40]={0};
	scanf("%d",&n);
	while(n--){
		int dec[4]={0};
		scanf("%s",bin);
		for(int i = 0;i < 4;i ++){
			for(int j = 8 * i;j < 8 * (i + 1);j++){
				dec[i] += (bin[j] - '0') * pow(2.0,7.0 - (j % 8));   //取模实现指数循环
			}
		}
		printf("%d.%d.%d.%d\n",dec[0],dec[1],dec[2],dec[3]);
	}
}