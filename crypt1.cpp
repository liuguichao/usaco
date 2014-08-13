/*
ID: liuguic1
PROG: crypt1
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

bool check(int value,vector<bool> &flag);
int main()
{
	ofstream fout("crypt1.out");
	ifstream fin("crypt1.in");
	int n;
	fin>>n;
	vector<int> list;
	vector<bool> flag(10,false);
	int tmp;
	while(fin>>tmp)
	{
		list.push_back(tmp);
		flag[tmp]=true;
	}

	
	int mult,product1,product2,result;
	int count=0;
	for(int i=0;i!=n;++i)
	{
		for(int j=0;j!=n;++j)
		{			
			for(int k=0;k!=n;++k)
			{
				mult=list[i]*100+list[j]*10+list[k];
				for(int l=0;l!=n;++l)
				{
					product1=mult*list[l];
					if(product1>999||check(product1,flag)==false) continue;
					for(int m=0;m!=n;++m)
					{
						product2=mult*list[m];
						if(product2>999||check(product2,flag)==false) continue;
						result=product1+product2*10;
						if(result>9999||check(result,flag)==false) continue;
						count++;
					}

				}

			}
		}
	}
	fout<<count<<endl;	
	
	return 0;
}
bool check(int value,vector<bool> &flag)
{
	do
	{
		int mod=value%10;
		if(flag[mod]==true)
			value/=10;
		else break;
	}while(value!=0);

	if(value==0)	
		return true;
	else return false;	
}