/*
ID: liuguic1
PROG: ride
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string comet, group;
	int cNum, gNum;
	//fin >> comet;
	//cout << comet << endl;
	
	while (fin >> comet >> group)
	{
		cNum = gNum = 1;
		for (auto c : comet)
			cNum *= (c - 'A') + 1;
		for (auto c : group)
			gNum *= (c - 'A') + 1;
		if (cNum % 47 == gNum % 47)
			fout << "GO" << endl;
		else fout << "STAY" << endl;
	}
	
	return 0;
}