#include<cstdio>
#include<cstdlib>
#include<cstring>
int less(const void *p1,const void *p2)
{
	return *(char*)p1 - *(char*)p2;
}
int greater(const void *p1,const void *p2)
{
	return *(char*)p2 - *(char*)p1;
}
int main()
{
	char a[5];
	while(scanf("%s",a) && a[0] != '-'){
		printf("N=%s:\n",a);
		if(((a[0] == a[1]) && (a[1] == a[2]) && (a[2] == a[3])) || strlen(a) != 4){    //相同或者长度不是4的
			printf("No!!\n");    //大小写。。。。囧
			continue;
		}
		int max,min,t = atoi(a),n = 0;
		while(t != 6174 && t){
			qsort(a,4,sizeof(char),greater);
			max = atoi(a);
			qsort(a,4,sizeof(char),less);
			min = atoi(a);
			t = max - min;
			printf("%d-%d=%d\n",max,min,t);
			n ++;
			if(t == 999){
				printf("999-999=0\nOk!! %d times\n",n + 1);
				n = 0;
				break;
			}
			for(int i = 3,tmp = t;i >= 0;i --){
				a[i] = '0' + tmp % 10;     //int转char要注意+0
				tmp /= 10;
			}
		}
		if(t != 999)printf("Ok!! %d times\n",n);
	}
	return 0;
}