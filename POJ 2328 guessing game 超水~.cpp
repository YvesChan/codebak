#include<cstdio>
int main()
{
	int max = 11,min = 0,t;
	char s1[10],s2[10];
	while(scanf("%d",&t) && t){
		scanf("%s%s",s1,s2);       //ԭ����gets�����⣨Ӧ����get��\n)���ɴ���������= =
		if(s2[0] == 'h' && t < max)max = t;
		if(s2[0] == 'l' && t > min)min = t;
		if(s2[0] == 'o'){
			if(t < max && t > min)printf("Stan may be honest\n");
			else printf("Stan is dishonest\n");
			max = 11;
			min = 0;
		}
	}
	return 0;
}