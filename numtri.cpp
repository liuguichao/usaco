/*
ID: liuguic1
PROG: numtri
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ofstream fout("numtri.out");
	ifstream fin("numtri.in");	
	int n;// row num
	fin>>n;
	int temp;
	vector<vector<int>> numtri;//two dimensional arrary
	for(int i=1;i!=n+1;++i)//1...n
	{
		vector<int> row;
		for(int j=0;j!=i;++j)//each row i has i items
		{
			fin>>temp;
			row.push_back(temp);
		}
		numtri.push_back(row);
	}
	vector<int> orignNextRow;
	for(int row=0;row!=numtri.size()-1;++row)
	{
		orignNextRow=numtri[row+1];
		for(int col=0;col!=numtri[row].size();++col)
		{
			int accum=numtri[row][col]+orignNextRow[col];
			if(accum>numtri[row+1][col])
				numtri[row+1][col]=accum;
			
			numtri[row+1][col+1]+=numtri[row][col];
		}
	}
	
	sort(numtri[n-1].begin(),numtri[n-1].end(),greater<int>());
	fout<<numtri[n-1][0]<<endl;
	return 0;
}

