#include<iostream>
#include<string>
using namespace std;
void sum(char a[],char b[])
{int c[1001]={0};
 int i=strlen(a);   //a��λ��
 int j=strlen(b);   //b��λ��
 int t=0,f=0;        //c���±꣬��λ����j
 i--;j--;    //��1λ
 for(;i>=0&&j>=0;){
 c[t]=a[i]+b[j]-96+f;     //�ַ�תint
 if(c[t]>9){
	 f=1;
	 c[t]-=10;
 }else
	 f=0;          //��λ
 t++;i--;j--;
 }
 while(i>=0){          //��a��b������a����c
	 c[t]=a[i]-48+f;
	 if(c[t]>9){
		 f=1;
		 c[t]=0;
	 }else
		 f=0;
	 t++;i--;
 }
 while(j>=0){
	 c[t]=b[j]-48+f;
	 if(c[t]>9){
		 f=1;
		 c[t]=0;
	 }else
		 f=0;
	 t++;j--;
 }
 if(f==1){        //���Ľ�λ
	 c[t]=1;
	 t++;
 }
 cout<<a<<" + "<<b<<" = ";
 while(c[--t]==0)t--;
 for(;t>=0;t--)cout<<c[t];
 cout<<endl;
}
int main()
{int n,ca;
 char a[1001]={'\0'},b[1001]={'\0'};
 cin>>n;
 for(ca=1;n>0;n--,ca++){
	 cin>>a>>b;
	 cout<<"Case "<<ca<<":"<<endl;
	 sum(a,b);
	 if(n!=1)cout<<endl;        //ע�����û�п���
 }
}