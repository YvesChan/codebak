#include<cstdio>
#include<cstring>
int main()
{

	int n,t,i,j,sum=0;
	while(scanf("%d",&n) && n){
		char a[22]={'\0'};
		char c[5000]={'\0'};
		scanf("%s",c);
		t = strlen(c);
		for(i = 0;i < t;i ++){
			for(j = 0;j < n;j ++)
				if(a[j] == c[i]){a[j] = '\0';break;}      //�ȼ���Ƿ�����ͬ��Ԫ�أ���������Ϊ0
			if(j < n)continue;                            //�������������������һ��C[i]�Ա�
			for(j = 0;j < n;j ++)
				if(a[j] == '\0'){a[j] = c[i];break;}      //�п�λ��д��
			if(j == n)sum++;                              //��������+1
		}
		if(!sum)printf("All customers tanned successfully.\n");
		else printf("%d customer(s) walked away.\n",sum/2);
		sum = 0;
	}
	return 0;
}