/*
ID: liuguic1
PROG: namenum
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
bool isContainKeyword(vector<string> &name,string key);
int main()
{
	 
	ofstream fout("namenum.out");
	ifstream fin("namenum.in");	

	string sn;
	fin>>sn;
	int len=sn.length();

	map<char,vector<char>> keys;
	keys['2']={'A','B','C'};
	keys['3']={'D','E','F'};
	keys['4']={'G','H','I'};
	keys['5']={'J','K','L'};
	keys['6']={'M','N','O'};
	keys['7']={'P','R','S'};
	keys['8']={'T','U','V'};
	keys['9']={'W','X','Y'};

	ifstream data("dict.txt");
	//map<string,int> dict;
	vector<string> dict;
	string s;
	while(data>>s)
	{
		if(s.length()==len)//filter,only keep dict items which length is equal to sn
		dict.push_back(s);
	}
	

	//visit by level
	queue<string> list;
	vector<string> temp;
	string str;
	list.push("");//push a root item
	for(int i=0;i!=sn.length();++i)
	{		
		//pop current substring of name,push into a vector
		while(!list.empty())
		{
			temp.push_back(list.front());
			list.pop();
		}
		//visit the temp subname list
		for(int  k=0;k!=temp.size();++k)
		{
			//add a new key to subname
			for(int j=0;j!=keys[sn[i]].size();++j)
			{
				str=temp[k];
				str+=keys[sn[i]][j];
				if(isContainKeyword(dict,str))//filter,eliminate the invalid name in advance,reduce the scale
					list.push(str);
			}
		}	
		temp.clear();			
	}	
	
	//copy queue to vector,for visit freely
	vector<string> nameList;
	while(!list.empty())
	{
		nameList.push_back(list.front());
			list.pop();
	}

	bool found=false;
	if(nameList.size()<dict.size())//keeping to search less items list,in this case,more faster
	{
		auto it=nameList.begin();
		while(it!=nameList.end())
		{
			auto item=find(dict.begin(),dict.end(),*it);
			if(item!=dict.end())
			{
				fout<<*item<<endl;
				found=true;
			}
			++it;
		}
	}
	else
	{
		auto it=dict.begin();
		while(it!=dict.end())
		{
			auto item=find(nameList.begin(),nameList.end(),*it);
			if(item!=nameList.end())
			{
				fout<<*item<<endl;
				found=true;
			}
			++it;
		}

	}
	if(!found)
		fout<<"NONE"<<endl;
	return 0;
}

bool isContainKeyword(vector<string> &name,string key)
{
	for(int i=0;i!=name.size();++i)
	{
		if(name[i].find(key)!=string::npos)
			return true;
	}	
	return false;
}