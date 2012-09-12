#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string num[100001];
int main()
{
	int n;
	char t[80];     //喵的这个开小的，然后RE  = =
	scanf("%d",&n);
	for(int i = 0;i < n;i ++){
		scanf("%s",t);
		for(int k = 0;k < strlen(t);k ++){
			if(t[k] == '-')continue;
			if(t[k] >= '0' && t[k] <= '9')num[i]+=t[k];
			if(t[k] >= 'A' && t[k] <= 'C')num[i]+='2';
			if(t[k] >= 'D' && t[k] <= 'F')num[i]+='3';
			if(t[k] >= 'G' && t[k] <= 'I')num[i]+='4';
			if(t[k] >= 'J' && t[k] <= 'L')num[i]+='5';
			if(t[k] >= 'M' && t[k] <= 'O')num[i]+='6';
			if(t[k] >= 'P' && t[k] <= 'S')num[i]+='7';
			if(t[k] >= 'T' && t[k] <= 'V')num[i]+='8';
			if(t[k] >= 'W' && t[k] <= 'Y')num[i]+='9';
		}
	}
	sort(&num[0],&num[0] + n);
	int tmp = 0,flag = 0;
	for(int i = 0;i < n;i ++){
		if(num[i] == num[i+1])tmp ++;
		else if(tmp){
			printf("%s-%s %d\n",num[i].substr(0,3).data(),num[i].substr(3).data(),tmp + 1);   //返回子串（string），转成char[]
			flag = 1;   //标记已输出
			tmp = 0;
		}
	}
	if(!flag)printf("No duplicates.\n");
	return 0;
}
//5796kB	710ms		


//附标程：1948kB	410ms
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char map[] = "22233344455566677778889999";
char str[80], telNumbers[100000][9];

int compare(const void *elem1,const void *elem2)
{
	return (strcmp((char*)elem1, (char*)elem2));     //为函数模板sort 定义数组元素的比较函数
}

void standardizeTel(int n)
{
	int j, k;
	j = k = -1 ;
	while ( k<8 ) {
		j++;
		if ( str[j] == '-' )
			continue;
		k++;
		if (k==3) {
			telNumbers[n][k]='-';
			k++;
		}
		if(str[j]>='A' && str[j]<='Z'){
			telNumbers[n][k] = map[str[j]-'A'];
			continue;
		}
		telNumbers[n][k]=str[j];
	}
	telNumbers[n][k]='\0';
	return;
}

int main()
{
	int n,i,j;
	bool noduplicate;
	scanf("%d",&n);
	for(i=0;i<n;i++){       //输入电话号码，存储到数组telNumbers 中
		scanf("%s",str);
		standardizeTel(i);      //将str 中的电话号码转换成标准形式，存储在telNumbers 的第i 行
	}
	qsort(telNumbers,n,9,compare);//对输入的电话号码进行排序
	noduplicate = true;
	i=0;
	while(i<n){            //搜索重复的电话号码，并进行输出
		j=i;
		i++;
		while(i<n && strcmp(telNumbers[i], telNumbers[j])==0) i++;
		if(i-j>1){
			printf("%s %d\n", telNumbers[j], i-j);
			noduplicate = false;
		}
	}
	if (noduplicate)printf("No duplicates.\n");
	return 0;
}
*/