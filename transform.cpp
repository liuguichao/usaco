/*
ID: liuguic1
PROG: transform
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<functional>
using namespace std;

#define N 10

char source[N][N];
char target[N][N];
char temp[N][N];
char trans[N][N];

int n;
bool isEqual();
void swap();
void copyTransToTemp();
int reflect();
int keep();
int rotate90();
int rotate180();
int rotate270();
int comb1();
int comb2();
int comb3();
int invalid();
void init();

int main()
{
	ofstream fout("transform.out");
	ifstream fin("transform.in");	
	fin >> n;
	
	for (int i = 0; i != n; ++i)
	for (int j = 0; j != n; ++j)	
		fin >> source[i][j];		

	for (int i = 0; i != n; ++i)
	for (int j = 0; j != n; ++j)
		fin >> target[i][j];	
	
	vector<function<int()>> callList;
	callList.push_back(rotate90);
	callList.push_back(rotate180);
	callList.push_back(rotate270);
	callList.push_back(reflect);
	callList.push_back(comb1);
	callList.push_back(comb2);
	callList.push_back(comb3);
	callList.push_back(keep);
	callList.push_back(invalid);	
	
	int status;
	for (auto it = callList.begin(); it != callList.end();++it)
	{
		init();
		status=(*it)();
		if (isEqual())
			break;
	}
	fout << status << endl;
	return 0;
}

//compare trans with target
bool isEqual()
{
	for (int i = 0; i != n; ++i)
	for (int j = 0; j != n; ++j)
	if (trans[i][j] != target[i][j])
		return false;
	return true;
}
//reset(copy source to temp)
void init()
{
	for (int i = 0; i != n; ++i)
	for (int j = 0; j != n; ++j)	
		temp[i][j] = source[i][j];

}
//do no change
int keep()
{
	for (int i = 0; i != n; ++i)
	for (int j = 0; j != n; ++j)
		trans[i][j] = temp[j][i];

	return 6;
}
//transform row to column
void swap()
{
	for (int i = 0; i != n; ++i)
	for (int j = 0; j != n; ++j)
		trans[i][j] = temp[j][i];	

	copyTransToTemp();
	
}
//copy trans to temp
void copyTransToTemp()
{	
	for (int i = 0; i != n; ++i)
	for (int j = 0; j != n; ++j)
		temp[i][j] = trans[i][j];
}
//reflect around a middle vertical line
int reflect()
{
	for (int i = 0; i != n; ++i)
	for (int j = 0; j != n; ++j)
		trans[i][j] = temp[i][n - j - 1];

	copyTransToTemp();

	return 4;
}
int rotate90()
{
	swap();
	reflect();
	return 1;
}
int rotate180()
{
	rotate90();
	rotate90();
	return 2;
}
int rotate270()
{
	rotate90();
	rotate90();
	rotate90();
	return 3;
}
int comb1()
{
	reflect();
	rotate90();
	return 5;
}
int comb2()
{
	reflect();
	rotate180();
	return 5;
}
int comb3()
{
	reflect();
	rotate270();
	return 5;
}
int invalid()
{
	return 7;
}