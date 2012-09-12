#include<cstdio>
#include<cstring>
int main()
{
	int n = 0,p = 0;
	char a[110][80],t[100];
	while(gets(t) && t[0]!='Q'){
		if(t[0] == 'V'){
			for(int i = 6;i <= 75;i ++)
				a[p][i-6] = t[i];
			p ++;
			n = p;
		}
		if(t[0] == 'B')p --;
		if(t[0] == 'F')p ++;
		if(t[0] == 'Q')return 0;
		if(p == 0)printf("http://www.acm.org/\n");
		else if(p == -1){printf("Ignored\n");p = 0;}
		else if(p == n+1){printf("Ignored\n");p = n;}
		else printf("%s\n",a[p-1]);
	}
	return 0;
}
