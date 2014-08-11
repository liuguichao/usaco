/*
ID: liuguic1
PROG: milk
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

int main()
{
	ofstream fout("milk.out");
	ifstream fin("milk.in");	
	int n,m;
	fin>>n>>m;
	multimap<int,int> supplier;
	int price,amount;
	while(fin>>price>>amount)
		supplier.insert(make_pair(price,amount));
	
	int charge=0;
	int need=n;
	auto it=supplier.begin();
	while(it!=supplier.end())
	{
		if(need>=it->second)
		{
			charge+=it->second*it->first;
			need-=it->second;
		}
		else
		{
			charge+=need*it->first;
			break;
		}
		
		it++;
	}
	fout<<charge<<endl;	
	
	return 0;
}
