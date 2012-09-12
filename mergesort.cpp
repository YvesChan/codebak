#include<cstdio>
#include<fstream>
using namespace std;
int tmp[100001],a[100001];
void mergesort(int a[],int tmp[],int left,int right,unsigned int& count){   //待排序数组地址，缓存数组（节省时间）
	int mid = (left + right) / 2;
	if(left == right)return;     //递归分割的最小子项
	mergesort(a,tmp,left,mid,count);      
	mergesort(a,tmp,mid + 1,right,count);    //分别对左右数组递归调用mergesort（invoke mergesort() recursively）
	for(int i = left;i <= right;i ++)tmp[i] = a[i];
	int i = left;
	int j = mid + 1;
	for(int k = left;k <= right;k ++){    //merge two sorted array
		if(i > mid)a[k] = tmp[j ++];      //judge the index of array out of size 
		else if(j > right)a[k] = tmp[i ++];
		else if(tmp[i] > tmp[j]){
			a[k] = tmp[j ++];
			count += mid + 1 - i;         //add remain number of left array(inversions with tmp[j])
		}
		else a[k] = tmp[i ++];
	}
}
int main()
{
	fstream file("d:\\IntegerArray.txt",ios::in);
	if(!file)printf("exception!");
	int i = 0;
	unsigned int count = 0;
	char s[10];
	while(file >> s)
		a[i ++] = atoi(s);
	mergesort(a,tmp,0,99999,count);
	printf("%u\n",count);
	return 0;
}