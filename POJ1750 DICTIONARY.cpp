#include<cstdio>
const int N = 100001,M = 11;
char list[N][M];

int main()
{
	int i = 0,j = 0,total = 0;
	while(scanf("%s",list[total]) != EOF)
		total ++;
	int blank = 0,substr = 0;
	printf("%s\n",list[0]);
	for(i = 1;i < total;i ++){
		j = substr = 0;
		while(list[i][j] != '\0'){      //control the space number whitout "0",TLE for this T_T
			if(list[i][j] != list [i - 1][j])break;
			else substr ++;
			j ++;
		}
		if(substr > blank)blank ++;      //main algorithm
		else blank = substr;
		for(int k = 0;k < blank;k ++)
				printf(" ");
		printf("%s\n",list[i]);
	}
	return 0;
}

