/*һ��ʼ�����Ŵ�n����ȡ2�����k��b��Ȼ�����������뿴�Ƿ��ߣ���ôû���뵽ֱ��ѡһ���㣬Ȼ��ȽϺ���
���б���أ�����Ȼ����Ƿ���顣����*/

#include<cstdio>
int main()
{
	int n;
	while(scanf("%d",&n)&&n){
		int a[701][2]={0},tmp=0,max=0,x,y;
		for(int i = 0;i < n;i ++)
			scanf("%d %d",&a[i][0],&a[i][1]);
		for(int i = 0;i < n;i++)
			for(int j = i+1;j < n;j ++){          //����������ȷ��һ��ֱ�ߣ��ٿ����������Ƿ�������
				for(int k = j+1;k < n;k ++){
					x = (a[i][1] - a[j][1]) * (a[i][0] - a[k][0]);    //ת��һ�£��ó˷����Ա���float������
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
