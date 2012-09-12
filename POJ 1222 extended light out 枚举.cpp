#include<cstdio>
#include<cstring>

int num[7][8],res[7][8],num2[7][8];

void change(int a,int b)
{
	if(!num2[a][b])num2[a][b] = 1;else num2[a][b] = 0;
	if(!num2[a-1][b])num2[a-1][b] = 1;else num2[a-1][b] = 0;
	if(!num2[a+1][b])num2[a+1][b] = 1;else num2[a+1][b] = 0;
	if(!num2[a][b-1])num2[a][b-1] = 1;else num2[a][b-1] = 0;
	if(!num2[a][b+1])num2[a][b+1] = 1;else num2[a][b+1] = 0;
}

int main()
{
	int n,i,j,k,tmp[8]={0};
	scanf("%d",&n);
	for(int count = 1;count <= n;count ++){
		memset(tmp,0,sizeof(tmp));            //枚举数组忘了重置，debug了N久。。。囧~~
		memset(res,0,sizeof(res));            //这个也debug了N久。。。。囧死
		for(i = 1;i < 6;i ++){
			for(int j = 1;j < 7;j ++)
				scanf("%d",&num[i][j]);            //在矩阵中间输入数据
		}
		for(k = 0;k < 64;k ++){
			i = 1;
			int t = k;
			while(t){
				tmp[i] = t % 2;               //0 - 63的二进制表示方式
				t /= 2;
				i++;
			}
			memcpy(num2,num,sizeof(num));      //副本
			for(j = 1;j < 7;j ++){
				res[1][j] = tmp[j];
				if(tmp[j])change(1,j);         //按下则change
			}
			for(i = 2;i < 6;i ++)
				for(j = 1;j < 7;j ++){
					if(num2[i-1][j]){          //若亮的则change其下面的按钮，同时记录
						res[i][j] = 1;
						change(i,j);
					}
				}
			for(j = 1;j < 7;j ++)
				if(num2[5][j])break;             //看最后一行是否均为0
			if(j == 7){
				printf("PUZZLE #%d\n",count);
				for(i = 1;i < 6;i ++){
					for(int j = 1;j < 7;j ++)
						if(j == 6)printf("%d\n",res[i][j]);
						else printf("%d ",res[i][j]);
				}
				break;
			}
			memset(res,0,sizeof(res));
		}
	}
	return 0;
}
