/*
ID: liuguic1
PROG: gift1
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	int np;
	fin>>np;

	vector<string> nameList;
	unordered_map<string,int> accountMap;
	string name;
	while(np--)
	{
		fin>>name;
		nameList.push_back(name);
		accountMap[name]=0;
	}
	int total,num,avg;
	while(fin>>name)
	{
		fin>>total>>num;
		accountMap[name]-=total;
		if(num==0)
			accountMap[name]+=total;
		else
		{
			avg=total/num;
			accountMap[name]+=total%num;
			while(num--)
			{
				fin>>name;
				accountMap[name]+=avg;
			}
		}

	}
	auto it=nameList.begin();
	while(it!=nameList.end())
	{		
		fout<<*it<<" "<<accountMap[*it]<<endl;
		++it;
	}
	
	return 0;
}