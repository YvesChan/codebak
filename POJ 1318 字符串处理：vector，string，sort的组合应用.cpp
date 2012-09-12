#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<string> dic;
	string t;
	for(int i = 0;;i++){
		cin>>t;
		if(t[0] == 'X')break;
		dic.push_back(t);           //push back输入数据，更新size值
	}
	sort(&dic[0],&dic[0] + dic.size());    //先按字典排序
	vector<string>dic2(dic.begin(),dic.end());     //复制一个排好序的副本
	for(int i = 0;i < dic2.size();i ++)
		sort(&dic2[i][0],&dic2[i][0] + dic2[i].size());    //对副本每个元素（string）排序
	while(cin>>t){
		if(t[0] == 'X')break;
		sort(&t[0],&t[0] + t.size());     //对输入的string排序
		int flag = 0;
		for(int i = 0;i < dic2.size();i ++)
			if(t == dic2[i]){cout<<dic[i]<<endl;flag = 1;}    //直接比较，按dic的字典顺序输出元素
		if(!flag)cout<<"NOT A VALID WORD\n";
		cout<<"******\n";
	}
	return 0;
}