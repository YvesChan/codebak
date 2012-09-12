#include<cstdio>
#include<cstring>
char s1[200],s2[200];
int gcd(int a,int b)
{
	return b ? gcd(b,a % b) : a;
}
int main()
{
	while(scanf("%s",s1) && s1[0] != '-'){
		scanf("%s",s2);
		if(!strcmp(s1,s2)){printf("appx(%s,%s) = 1\n",s1,s2);continue;}
		int max = 0,t = 0;
		int len1 = strlen(s1),len2 = strlen(s2);
		for(int i = 0;i < len1;i ++){
			for(int j = 0;j < len2;j ++){
				for(int i1 = i,j1 = j;i1 < len1 && j1 < len2;i1 ++,j1 ++)
					if(s1[i1] == s2 [j1])t ++;
				if(t > max)max = t;
				t = 0;
			}
		}
		if(!max){printf("appx(%s,%s) = 0\n",s1,s2);continue;}
		int x = max * 2,y = len1 + len2;
		printf("appx(%s,%s) = %d/%d\n",s1,s2,x / gcd(x,y),y / gcd(x,y));
	}
	return 0;
}