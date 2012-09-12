#include<cstdio>
int a[20],b[20];
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	for(int i = 0;x + y;i ++){
		if(x){a[i] = x;x /= 2;}
		if(y){b[i] = y;y /= 2;}
	}
	for(int i = 0;a[i];i ++)
		for(int j = 0;b[j];j ++)
			if(a[i] == b[j]){
				printf("%d\n",a[i]);
				return 0;
			}
	return 0;
}


/*µÝ¹é½â·¨£º
#include<cstdio>
int common(int x,int y)
{
	if(x == y)return x;
	if(x > y)return common(x / 2,y);
	return common(x,y / 2);
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",common(a,b));
	return 0;
}
*/