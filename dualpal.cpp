/*
ID: liuguic1
PROG: dualpal
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
string convert(int i,int base);
bool isPalindrome(string s);
bool isValid(int number);
vector<char> digit;//0123456789ABCDEFGHIJ
int main()
{

	ofstream fout("dualpal.out");
	ifstream fin("dualpal.in");	
	int n,m;
	fin>>n>>m;
	
	for(int i=0;i!=10;++i)
		digit.push_back('0'+i);	
	
	
	int count=0;
	for(int number=m+1;;++number)
	{
		if(isValid(number))
		{
			fout<<number<<endl;
			count++;
			if(count==n)
				break;
		}
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
bool isValid(int number)
{
	int count=0;
	string str;
	for(int b=2;b<=10;++b)
	{
		str=convert(number,b);
		if(isPalindrome(str))
			count++;
		if(count==2)
			return true;
	}
	return false;
}