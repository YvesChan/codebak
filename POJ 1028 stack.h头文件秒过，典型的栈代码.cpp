#include<iostream>
#include<fstream>
#include<string>
#include<stack>
using namespace std ;
int main(){
    stack<string> a ;
    stack<string> b ;           //b��¼BACK����ǰ��ҳ��
    string c ;
    a.push("http://www.acm.org/") ;
    //fstream cin("x.in") ;
    while(cin>>c&&c!="QUIT"){
        if(c=="VISIT"){
            cin >> c ;
            a.push(c) ;
            while(!b.empty())   b.pop() ; //b��Ϊ����b���
            cout << c << endl ;
        }else
        if(c=="BACK"){
            c = a.top() ;
            a.pop() ;
            if(a.empty()){
                cout << "Ignored" << endl ;
                a.push(c) ;
            }
            else{
                cout << a.top() << endl ;
                b.push(c) ;
            }
        }else{
            if(b.empty())   cout << "Ignored" << endl ;
            else{
                cout << b.top() << endl ;
                a.push(b.top()) ;
                b.pop() ;
            }
        }
    }
    return 0 ;
}