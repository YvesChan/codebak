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
		dic.push_back(t);           //push back�������ݣ�����sizeֵ
	}
	sort(&dic[0],&dic[0] + dic.size());    //�Ȱ��ֵ�����
	vector<string>dic2(dic.begin(),dic.end());     //����һ���ź���ĸ���
	for(int i = 0;i < dic2.size();i ++)
		sort(&dic2[i][0],&dic2[i][0] + dic2[i].size());    //�Ը���ÿ��Ԫ�أ�string������
	while(cin>>t){
		if(t[0] == 'X')break;
		sort(&t[0],&t[0] + t.size());     //�������string����
		int flag = 0;
		for(int i = 0;i < dic2.size();i ++)
			if(t == dic2[i]){cout<<dic[i]<<endl;flag = 1;}    //ֱ�ӱȽϣ���dic���ֵ�˳�����Ԫ��
		if(!flag)cout<<"NOT A VALID WORD\n";
		cout<<"******\n";
	}
	return 0;
}