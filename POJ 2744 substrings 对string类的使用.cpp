#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t --){
		cin>>n;
		int minsize = 101,min,len,i,j;
		string s[101];
		for(int i = 0;i < n;i ++){
			cin>>s[i];
			if(s[i].size() < minsize){minsize = s[i].size();min = i;}    //ȡ����ַ���������ö���Ӵ�
		}
		for(len = minsize;len > 0;len --){     //�ӳ�ȡ����
			for(i = 0;i + len <= minsize;i ++){
				string subs = s[min].substr(i,len);    //�Ӵ�
				char tmp[101];
				strcpy(tmp,subs.c_str());
				string subr = _strrev(tmp);    //���Ӵ���strrve������ı����tmp��������tmp
				for(j = 0;j < n;j ++)
					if(s[j].find(subs) == string::npos && s[j].find(subr) == string::npos)break; 
				if(j == n){cout<<len<<endl;goto next;}    //�����goto�õĺñ�Ť
			}
		}
		cout<<"0\n";
next:continue;
	}
	return 0;
}