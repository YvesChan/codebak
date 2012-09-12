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
		memset(tmp,0,sizeof(tmp));            //ö�������������ã�debug��N�á�������~~
		memset(res,0,sizeof(res));            //���Ҳdebug��N�á�����������
		for(i = 1;i < 6;i ++){
			for(int j = 1;j < 7;j ++)
				scanf("%d",&num[i][j]);            //�ھ����м���������
		}
		for(k = 0;k < 64;k ++){
			i = 1;
			int t = k;
			while(t){
				tmp[i] = t % 2;               //0 - 63�Ķ����Ʊ�ʾ��ʽ
				t /= 2;
				i++;
			}
			memcpy(num2,num,sizeof(num));      //����
			for(j = 1;j < 7;j ++){
				res[1][j] = tmp[j];
				if(tmp[j])change(1,j);         //������change
			}
			for(i = 2;i < 6;i ++)
				for(j = 1;j < 7;j ++){
					if(num2[i-1][j]){          //��������change������İ�ť��ͬʱ��¼
						res[i][j] = 1;
						change(i,j);
					}
				}
			for(j = 1;j < 7;j ++)
				if(num2[5][j])break;             //�����һ���Ƿ��Ϊ0
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
