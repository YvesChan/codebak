#include<iostream>
using namespace std;
//ŷ����ó���
int gcd(int a,int b){
		return (b==0)?a:gcd(b,a%b);
	}
int main(){
	int a,b;
	while(1){
		cin>>a>>b;
		cout<<gcd(a,b)<<endl<<endl;;
	}
}
