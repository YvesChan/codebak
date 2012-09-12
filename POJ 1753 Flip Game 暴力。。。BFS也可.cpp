#include<cstdio>
#include<cstring>
#include<cstdlib>
char table[6][7];
char copy[6][7];
int firstline[5],count;
void change(int a,int b)
{
	if(copy[a][b] == 'b')copy[a][b] = 'w';else copy[a][b] = 'b';
	if(copy[a-1][b] == 'b')copy[a-1][b] = 'w';else copy[a-1][b] = 'b';
	if(copy[a][b-1] == 'b')copy[a][b-1] = 'w';else copy[a][b-1] = 'b';
	if(copy[a+1][b] == 'b')copy[a+1][b] = 'w';else copy[a+1][b] = 'b';
	if(copy[a][b+1] == 'b')copy[a][b+1] = 'w';else copy[a][b+1] = 'b';
	count ++;
}

int main()
{
	int i,j,t,min = 16;
	for(i = 1;i < 5;i ++)
			scanf("%s",&table[i][1]);
	for(t = 0;t < 16;t ++){
		memset(firstline,0,sizeof(firstline));
		int tmp = t,k = 1;          //WTF = =here the problem k which got me in trouble
		while(tmp){                       //create a binary array
			firstline[k] = tmp % 2;
			tmp /= 2;
			k ++;
		}

		memcpy(copy,table,sizeof(table));      //try to change to all white
		count = 0;
		for(k = 1;k < 5;k ++)
			if(firstline[k] == 1)change(1,k);
		for(i = 2;i < 5;i ++)
			for(j = 1;j < 5;j ++){
				if(copy[i-1][j] == 'b')change(i,j);
/*
				for(int m = 1;m < 5;m ++){
					for(int n = 1;n < 5;n ++)
						printf("%c ",copy[m][n]);
					printf("\n");
				}
				system("pause");
				system("cls");
*/
			}
		for(j = 1;j < 5;j ++)
			if(copy[4][j] != 'w')break;
		if(j == 5 && count < min)min = count;   //mark the min

		memcpy(copy,table,sizeof(table));     //try to change to all black
		count = 0;
		for(k = 1;k < 5;k ++)
			if(firstline[k] == 1)change(1,k);
		for(i = 2;i < 5;i ++)
			for(j = 1;j < 5;j ++)
				if(copy[i-1][j] == 'w')change(i,j);    //difference!
		for(j = 1;j < 5;j ++)
			if(copy[4][j] != 'b')break;
		if(j == 5 && count < min)min = count;
	}
	if(min != 16)printf("%d\n",min);
	else printf("Impossible\n");
	return 0;
}