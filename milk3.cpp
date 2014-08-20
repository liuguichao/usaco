/*
ID: liuguic1
PROG: milk3
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
bool found[21][21][21];
vector<int> solutions;
int A,B,C;
void DFS(int a,int b,int c);
int main()
{
	ofstream fout("milk3.out");
	ifstream fin("milk3.in");	
	fin>>A>>B>>C;
	int a=0,b=0,c=C;
	memset(found,0,sizeof(found));

	DFS(a,b,c);
	
	sort(solutions.begin(),solutions.end(),less<int>());

	fout<<*solutions.begin();
	for(auto it=solutions.begin()+1;it!=solutions.end();++it)
		fout<<" "<<*it;
	fout<<endl;
	
	return 0;
}
void DFS(int a,int b,int c)
{
	if(found[a][b][c]) return;
	found[a][b][c]=true;
	if(a==0)
		solutions.push_back(c);

	int space;

	//A->B
	space=B-b;
	if(a>=space) 
		DFS(a-space,B,c);
	else 
		DFS(0,b+a,c);

	//A->C
	space=C-c;
	if(a>=space) 
		DFS(a-space,b,C);
	else 
		DFS(0,b,c+a);

	//B->A
	space=A-a;
	if(b>=space)
		DFS(A,b-space,c);
	else
	 	DFS(a+b,0,c);

	//B->C
	 space=C-c;
	if(b>=space)
		DFS(a,b-space,C);
	else 
		DFS(a,0,c+b);
	
	//C->A
	space=A-a;
	if(c>=space)
		DFS(A,b,c-space);
	else
		 DFS(a+c,b,0);

	//C->B
	space=B-b;
	if(c>=space)
		DFS(a,B,c-space);
	else 
		DFS(a,b+c,0);
}


