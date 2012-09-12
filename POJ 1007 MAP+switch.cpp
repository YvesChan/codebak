������STL���map����һ�θ��ܵ�����ǿ���Լ�һ���õ����ݽṹ����Ҫ�ԣ����map�õ�������= =��

���������õ���һ��ţ�˵�˼�룬�ܾ��塭����������Ҫѧϰһ��O��nlogn���ķ����������㷨

#include <iostream>
#include <string>
#include <map>

using namespace std;

int reverseCount(string DNA, int length)
{
int countA = 0, countC = 0, countG = 0, countT = 0;
int nReverse = 0;
for(int i = length - 1; i >= 0; i--){
   switch(DNA[i]){
    case 'A':countA ++;
      break;
    case 'C':countC ++;
      nReverse += countA;
      break;
    case 'G':countG ++;
      nReverse += (countA + countC);
      break;
    case 'T':countT ++;
      nReverse += (countA + countC + countG);
      break;
    default: exit(-1);
      break;
   }
}
return nReverse;
}

int main()
{
int length, n;
string DNA;
multimap<int, string> hash;
cin >> length >> n;
for(int i = 0; i < n; i++){
   cin >> DNA;
   int temp = reverseCount(DNA, length);
   hash.insert(make_pair(temp, DNA));
}
multimap<int, string>::iterator itr;
for(itr = hash.begin(); itr != hash.end(); ++itr)
   cout << itr->second << endl;
cout << endl;
return 0;
}