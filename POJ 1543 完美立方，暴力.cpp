#include<cstdio>
int main()
{
	int n,a,b,c,d,i,t[200]={0},cube[101]={0};     //��ʼ���鿪С�ˣ���RE��һ�� = =
	scanf("%d",&n);
	for(i = 2;i <= n;i ++)
		cube[i] = i * i * i;      //����Ż���һ�£���ʡ��һ��ʱ�� = =
	for(a = 6;a <= n;a ++)
		for(b = 2;b < a;b ++)
			for(c = 2;c < a;c ++)
				for(d = 2;d < a;d ++){
					if(cube[a] == cube[b] + cube[c] + cube[d]){
						for(i = 0;t[i];i ++)
							if(t[i] == b * c * d)break;     //�Ƚϳ˻�����ͬ�Ͳ����
						if(!t[i]){
							printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
							t[i] = b * c * d;               //��ͬ�ͼ����¼
						}
					}
					else if(cube[a] < cube[b] + cube[c] + cube[d])break;
				}
	return 0;
}