#include<cstdio>
int main()
{
	int n,m,x,y;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n < m){x = n;y = m;}
		else {x = m;y = n;}
		int t,count=1,max=0;
		for(int i = x;i <= y;i ++){
			t = i;
			while(t != 1){
				if(t%2 == 1)t = 3 * t + 1;
				else t = t / 2;
				count ++;
			}
			if(count > max)max = count;
			count = 1;
		}
		printf("%d %d %d\n",n,m,max);
	}
	return 0;
}

/*���ݺ�ˮ��ֻ��1-10000��������ķ�Χ����һ�㣬����ö�پ��ܲ������ˡ�������ʵ��������ܸ��ʺϵ㣬
  ���߼����Ż�������*/

/*������һ�δ����Ĵ��룺
  #include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int d[10003];

int main()
{
    //freopen("input.txt","r",stdin);
    int i,j,t;
    memset(d,0,sizeof(d));
    for(int k=2;k<10003;k++)//���
    {
        t=k;
        while(1!=t)
        {
            if(t&1)        //���ð�λ��ķ�ʽ��ʾ������mark��
            {
                t=t*3+1;
            }
            else  t>>=1;
            d[k]++;
        }
    }
    while(cin>>i>>j)
    {

        int max=0,t=0;
        cout<<i<<" "<<j<<" ";
        if(i>j)
        {
            i^=j;j^=i;i^=j;       //�������ʵ�ֽ�����mark��
        }
        for(int k=i;k<=j;k++)
        {


          if(max<d[k])
            max=d[k];
        }


        cout<<max+1<<endl;
    }
    return 0;
}
*/