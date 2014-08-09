/*
ID: liuguic1
PROG: milk2
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool sortByStart(pair<int,int> a,pair<int,int> b)
{
	if (a.first<b.first) return true;
	else if(a.first==b.first)
		return a.second<b.second;
	return false; 
}
int main()
{
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");

	int n;
	fin >> n;
	int begin, end;	

	vector<pair<int, int>> timeList;
	
	while (fin >> begin >> end)
		timeList.push_back(make_pair(begin, end));

	sort(timeList.begin(),timeList.end(),sortByStart);	

	int maxMilk = 0, maxIdle = 0, sum = 0;
	int interval = 0, start,stop;
	bool isContinue = false;
	for (auto it = timeList.begin();it != timeList.end(); ++it)
	{	
		if (!isContinue)
		{
			start = it->first;		
			stop=it->second;	
		}

		auto next=it+1;

		if(next!=timeList.end())
		{

			interval = next->first - stop;

			if(interval <= 0)
			{
				if(next->second>stop)
					stop=next->second;
				

				isContinue = true;
				continue;
			}
			else
			{
				isContinue = false;
				if (interval>maxIdle)
					maxIdle = interval;
			}
		}
		
		sum = stop - start;
		if (sum>maxMilk)
			maxMilk = sum;		
	}	

	fout << maxMilk << " " << maxIdle << endl;

	return 0;
}
