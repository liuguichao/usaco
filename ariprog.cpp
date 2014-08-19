/*
ID: liuguic1
PROG: ariprog
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	ofstream fout("ariprog.out");
	ifstream fin("ariprog.in");
	int n,m;
	fin>>n>>m;
	
	vector<int> list;
	for(int i=0;i<=m;++i)
	{
		int ii=i*i;
		for(int j=i;j<=m;++j)		
			list.push_back(ii+j*j);			
	}
	//sort then remove duplicated value
	sort(list.begin(),list.end(),less<int>());
	auto it=unique(list.begin(),list.end());
	list.resize(distance(list.begin(),it));	
	
	//for boost search
	vector<bool> mask(list[list.size()-1]+1,false);	
	for(int i=0;i!=list.size();++i)
		mask[list[i]]=true;
	
	
	vector<pair<int,int>> result;
	for(auto it=list.begin();it!=list.end()-n+1;++it)
	{
		int start=*it;
		for(auto next=it+1;next!=list.end();++next)
		{
			int diff=*next-start;		
			int last=start+diff*(n-1);
			if(last>*(list.end()-1)) break;
			int count=2;
			while(mask[last]==true)
			{
				last-=diff;
				count++;
				if(count==n)
					break;			
			}	
			if(count==n)			
				result.push_back(make_pair(start,diff));	
			
		}
	}
	if(result.size()==0)
		fout<<"NONE"<<endl;
	else	
	{
		sort(result.begin(),result.end(),[](pair<int,int>a,pair<int,int>b){return a.second<b.second;});
		for(int i=0;i!=result.size();++i)
		fout<<result[i].first<<" "<<result[i].second<<endl;
	}
		
	
	return 0;
}
