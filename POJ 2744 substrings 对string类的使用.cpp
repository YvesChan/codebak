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
			if(s[i].size() < minsize){minsize = s[i].size();min = i;}    //取最短字符串，从中枚举子串
		}
		for(len = minsize;len > 0;len --){     //从长取到短
			for(i = 0;i + len <= minsize;i ++){
				string subs = s[min].substr(i,len);    //子串
				char tmp[101];
				strcpy(tmp,subs.c_str());
				string subr = _strrev(tmp);    //逆子串，strrve函数会改变参数tmp，并返回tmp
				for(j = 0;j < n;j ++)
					if(s[j].find(subs) == string::npos && s[j].find(subr) == string::npos)break; 
				if(j == n){cout<<len<<endl;goto next;}    //这里的goto用的好别扭
			}
		}
		cout<<"0\n";
next:continue;
	}
	return 0;
}