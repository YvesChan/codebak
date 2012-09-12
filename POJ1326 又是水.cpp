#include<cstdio>
#include<cmath>
int main()
{
	char a[20],b[20],c[3];
	int dis,sum = 0;
	while(scanf("%s",a)){
		if(a[0] == '0'){printf("%d\n",sum);sum = 0;continue;}
		if(a[0] == '#')break;
		scanf("%s%d%s",b,&dis,c);
		if(c[0] == 'F')sum += dis * 2;
		if(c[0] == 'B')sum += ceil(dis * 1.5);    //向上取整
		if(c[0] == 'Y'){
			if(dis <= 500)sum += 500;
			else sum += dis;
		}
	}
	return 0;
}