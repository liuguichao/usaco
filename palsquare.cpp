/*
ID: liuguic1
PROG: palsquare
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
string convert(int i,int base);
bool isPalindrome(string s);
vector<char> digit;//0123456789ABCDEFGHIJ
int main()
{
	 
	ofstream fout("palsquare.out");
	ifstream fin("palsquare.in");	
	int base;
	fin>>base;
	
	for(int i=0;i!=10;++i)
		digit.push_back('0'+i);
	for(int i=10;i<=base;++i)
		digit.push_back('A'+i-10);
	
	int square;
	string str;
	for(int i=1;i<=300;++i)
	{
		square=i*i;
		str=convert(square,base);
		if(isPalindrome(str))
			fout<<convert(i,base)<<" "<<str<<endl;
	}
	
	return 0;
}
string convert(int i,int base)
{
	string s;	
	int remain;
	do
	{
		remain=i%base;		
		i/=base;
		s.insert(0,1,digit[remain]);
	}while(i!=0);
	
	return s;
}
bool isPalindrome(string s)
{	
	int len=s.length();
	int n=len/2;
	for(int i=0;i!=n;++i)
	{
		if(s[i]!=s[len-1-i])
			return false;
	}
	return true;
}