#include<cstdio>
int num[25][25];
char table[25][25];
int x,y;
void get(int a,int b)
{
	num[a][b] = 1;    //标记
	if(a < 1 || b < 1 || a > y || b > x)return;
	if(table[a-1][b] == '.' && num[a-1][b] != 1)get(a - 1,b);
	if(table[a+1][b] == '.' && num[a+1][b] != 1)get(a + 1,b);
	if(table[a][b-1] == '.' && num[a][b-1] != 1)get(a,b - 1);
	if(table[a][b+1] == '.' && num[a][b+1] != 1)get(a,b + 1);
}
int main()
{
	int t1,t2,t = 0;
	while(scanf("%d%d",&x,&y) && x){
		for(int i = 1;i <= y;i ++)
			scanf("%s",&table[i][1]);    //输入数据，从[1]开始。。。
		for(int i = 1;i <= y;i ++)
			for(int j = 1;j <= x;j ++){
				num[i][j] = 0;
				if(table[i][j] == '@'){t1 = i;t2 = j;}    //清零顺便记录起始位置
			}
		get(t1,t2);
		for(int i = 1;i <= y;i ++)
			for(int j = 1;j <= x;j ++)
				if(num[i][j])t++;
		printf("%d\n",t);
		t = 0;
	}
	return 0;
}

/*
int f(int x, int y){
if(x < 0 || x >= W || y < 0 || y >= H)return 0; // 如果走出矩阵范围
	if(z[x][y] == '#')return 0;
	else{
		z[x][y] = '#'; // 将走过的瓷砖做标记
		return 1 + f(x - 1, y) + f(x + 1, y) + f(x, y - 1) + f(x, y + 1);
	}
}
*/