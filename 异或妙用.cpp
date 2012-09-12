/*Problem Description
Give you a sequence of number,in which except for one element,all number appears twice,your task is to find such a special one.
Input
The first line:N(N<=1000000)
The second line:a1,a2...an 
(Use 'scanf' instead of 'cin' to esacpe from TLE,and use 64_bit integer to hold the input)
Output
Only one number,the special one
Sample Input
5
1 1 2 2 3
Sample Output
3
*/

//怎么HDOJ一定要用int64 = =

#include<cstdio>
int main()
{
	int n;
	__int64 t,m;
	scanf("%d%I64d",&n,&t);
	while(--n){
		scanf("%I64d",&m);
		t ^= m;
	}
	printf("%I64d\n",t);
	return 0;
}




//qsort快排过
#include<cstdio>
#include<cstdlib>
int mycompare(const void *elem1,const void *elem2){
	__int64 *p1,*p2;
	p1=(__int64 *)elem1;
	p2=(__int64 *)elem2;
	if(*p1 - *p2 < 0)return -1;
	if(*p1 - *p2 == 0)return 0;
    if(*p1 - *p2 > 0)return 1;
}
__int64 n[1000010]={0};     //数组尽量开全局的
int main()
{
	int num;
	scanf("%d",&num);
	for(int i = 0;i < num;i ++)
		scanf("%I64d",&n[i]);
	qsort(n,num,sizeof(__int64),mycompare);
	for(int i = 0;i < num-1;i +=2)
		if(n[i] != n[i+1]){printf("%I64d\n",n[i]);return 0;}
	printf("%I64d\n",n[num-1]);
	return 0;
}