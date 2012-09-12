#include<cstdio>
#include<cstdlib>
const int MAXSIZE=26;
int anum[MAXSIZE],bnum[MAXSIZE];

int main(){
	char ch;
	int len1 = 0,len2 = 0,hash1 = 0,hash2 = 0;;
	while((ch=getchar())!='\n'){
		++anum[ch-'A'];
		len1 ++;
	}
	while((ch=getchar())!='\n'){
		++bnum[ch-'A'];
		len2 ++;
	}
	if(len1 != len2){printf("NO");return 0;}
	for(int i=0;i!=MAXSIZE;++i){
		hash1+=anum[i]*anum[i];
		hash2+=bnum[i]*bnum[i];
	}
	if(hash1==hash2)
		printf("YES");
	else
		printf("NO");
	return 0;
}