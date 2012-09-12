#include<cstdio>
#include<cstring>
int main()
{
	static char a[250],b[250];
	while(gets(a)){
		if(!strcmp(a,"START"))continue;
		if(!strcmp(a,"END")){
			printf("%s\n",b);
			memset(b,'\0',250 * sizeof(char));
			memset(a,'\0',250 * sizeof(char));
			continue;
		}
		if(!strcmp(a,"ENDOFINPUT"))break;
		for(int i = 0;i < strlen(a);i ++){
			if(a[i] >= 'A' && a[i] <= 'E')b[i] = a[i] + 21;
			else if(a[i] >='F' && a[i] <= 'Z')b[i] = a[i] - 5;
			else b[i] = a[i];
		}
	}
	return 0;
}