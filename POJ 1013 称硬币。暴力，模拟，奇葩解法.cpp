#include <iostream>
#include <string>
#include <fstream>
#include <memory.h>
using namespace std;

int main()
{
    int c[12][3];
    int res[3];
    int n, i, j;

    cin>>n;
    while(n--) {
        memset(c, 0, sizeof(c));
        memset(res, 0, sizeof(res));
        string s1, s2, s3;
        for(i=0; i<3; i++){
            cin>>s1>>s2>>s3;
            for(j=0; j<s1.size(); j++) {
                c[s1[j]-'A'][i] = 1;
                c[s2[j]-'A'][i] = -1;
            }
            if(s3=="even"){
                res[i] = 0;
            }
            else if(s3=="up"){
                res[i] = 1;
            }
            else {
                res[i] = -1;
            }
        }
        for(i=0; i<13; i++) {
            if(c[i][0]==res[0] && c[i][1]==res[1] && c[i][2]==res[2]) {
                cout<<char('A'+i)<<" is the counterfeit coin and it is heavy."<<endl;;
                break;
            }
            else if(c[i][0]==-res[0] && c[i][1]==-res[1] && c[i][2]==-res[2]) {
                cout<<char('A'+i)<<" is the counterfeit coin and it is light."<<endl;;
                break;
            }
        }
    }
    return 0;
}