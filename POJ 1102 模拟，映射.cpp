#include<cstdio>
#include<cstring>
char n1[11] = {"- -- -----"};
char n2[21] = {"|| | | |||| |  |||||"};
char n3[11] = {"  ----- --"};
char n4[21] = {"|| ||  | | ||| ||| |"};
char n5[11] = {"- -- -- --"};
int main()
{
	int s,i,j,k;
	char n[15];
	while(scanf("%d%s",&s,n) && s){
		int len = strlen(n);
		for(i = 0;i < len;i ++){
			printf(" ");
			for(j = 0;j < s;j ++)
				printf("%c",n1[n[i] - '0']);
			printf("  ");
		}
		printf("\n");             //第一行输出完毕
		for(i = 0;i < s;i ++){
			for(j = 0;j < len;j ++){
				printf("%c",n2[2 * (n[j] - '0')]);
				for(k = 0;k < s;k ++)
					printf(" ");
				printf("%c ",n2[2 * (n[j] - '0') + 1]);
			}
			printf("\n");
		}                          //第二行输出完毕
		for(i = 0;i < len;i ++){
			printf(" ");
			for(j = 0;j < s;j ++)
				printf("%c",n3[n[i] - '0']);
			printf("  ");
		}
		printf("\n");              //第三行
		for(i = 0;i < s;i ++){
			for(j = 0;j < len;j ++){
				printf("%c",n4[2 * (n[j] - '0')]);
				for(k = 0;k < s;k ++)
					printf(" ");
				printf("%c ",n4[2 * (n[j] - '0') + 1]);
			}
			printf("\n");
		}                      //第四行
		for(i = 0;i < len;i ++){
			printf(" ");
			for(j = 0;j < s;j ++)
				printf("%c",n5[n[i] - '0']);
			printf("  ");
		}
		printf("\n\n");           //第五行,中间空一行
	}
	return 0;
}
