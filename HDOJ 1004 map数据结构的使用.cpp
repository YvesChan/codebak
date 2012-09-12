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
    while(scanf("%d",&times)!=EOF&&times!=0)//因为它，我白白TLE了四次~~~~~ 
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
        cout<<stmp<<endl;//可以每次输出每次的结果~~~~，不必攒到最后输出 
        
    }
}