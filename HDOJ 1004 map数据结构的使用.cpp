#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "stdio.h"
using namespace std;

int main()
{
    int times;
    map<string,int> balloon;
    vector<string> colo;
    string stmp;
    while(scanf("%d",&times)!=EOF&&times!=0)//��Ϊ�����Ұװ�TLE���Ĵ�~~~~~ 
    {
        balloon.clear();
        for(int i=0;i<times;i++)
        {
            cin>>stmp;
            balloon[stmp]++;
            
        }
        map<string,int>::const_iterator itr;
        int max=-1;
        for(itr=balloon.begin();itr!=balloon.end();itr++)
        {
            if(itr->second>max)
            {
                max=itr->second;
                stmp=itr->first;
            }
        }
        cout<<stmp<<endl;//����ÿ�����ÿ�εĽ��~~~~�������ܵ������� 
        
    }
}