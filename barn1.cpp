/*
ID: liuguic1
PROG: barn1
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	ofstream fout("barn1.out");
	ifstream fin("barn1.in");

	int m,s,c;
	fin>>m>>s>>c;
	if(m>=c)
	{
		fout<<c<<endl;
		return 0;
	}
	vector<int> stalls;
	int number;
	while(fin>>number)		
		stalls.push_back(number);
	
	sort(stalls.begin(),stalls.end(),less<int>());

	vector<pair<int,int>>diff={make_pair(stalls[0],0)};	
	for(int i=1;i!=stalls.size();++i)	
		diff.push_back(make_pair(stalls[i],stalls[i]-stalls[i-1]));	
	
	sort(diff.begin(),diff.end(),[](pair<int,int>a,pair<int,int>b){return a.second>b.second;});


	int len=*stalls.rbegin()-*stalls.begin()+1;
	for(int i=0;i!=m-1;++i)
	{
		len-=diff[i].second-1;
	}

	fout<<len<<endl;
	return 0;
}
