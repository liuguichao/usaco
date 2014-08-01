/*
ID: liuguic1
PROG: beads
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int mod(int pos, int len)
{	
	while(pos < 0)
	pos += len;
    return pos%len;
}
//dir:forward=1,backward=-1
int count(string& s, int start, int dir, int len)
{
	char pre = 'w';

	int pos, i;
	if (dir>0) pos = start;//forward
	else pos = mod(start - 1, len);//backword
	
	for (i = 0; i != len;++i)
	{
		if (pre == 'w'&s[pos] != 'w')		
			pre = s[pos];			
		
		if (pre!='w'&&s[pos] != pre&&s[pos] != 'w')
				break;

		pos = mod(pos + dir, len);
	}
	return i;
}

int main()
{
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	int n;
	fin >> n;
	string s;
	fin >> s;

	int sum = 0, max = 0;
	for (int i = 0; i != n; ++i)
	{
		sum = count(s, i, 1, n) + count(s, i, -1, n);
		if (sum>max)
			max = sum;
	}
	
	//rrrwwrrrr 
	if (max>n)
		max = n;

	fout << max << endl;


	return 0;
}
