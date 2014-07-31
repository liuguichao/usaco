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

int main()
{
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	int n;
	fin>>n;
	string s;
	fin>>s;
	s+=s;
	//wwwbbrwrbrbrrbrbrwrwwrbwrwrrb|wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
	int i,j,state,count,max=0;
	char key;
	
	for(i=0;i!=n;++i)
	{		
		key=s[i];
		if(key=='w')
			state=0;
		else state=1;

		j=i;
		count=0;
		while(state<=2)
		{
			while(j<n+i&&(s[j]==key||s[j]=='w'))
			{
				count++;
				j++;			
			}
			state++;
			key=s[j];
		}
		if(count>max)
			max=count;
	}
	
	fout<<max<<endl;
	return 0;
}
