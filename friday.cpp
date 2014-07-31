/*
ID: liuguic1
PROG: friday
LANG: C++11
*/
#include<iostream>
#include<fstream>

using namespace std;
typedef int Day_Of_Week;//day of week,range from 0 to 6,with 0 is sunday
bool isLeapYear(int year);
int main()
{
	ofstream fout("friday.out");
	ifstream fin("friday.in");
	int n;
	fin>>n;
	int daysOfMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//month numbers plus 1. In this case,subscript is more meaningful 
	int counter[7]={0,0,0,0,0,0,0};//sun,mon,tue,wed,thu,fri,sat
	int yearBegin=1900,dayNo=13;
	Day_Of_Week firstDayOfMonth=1;//the 1900-1-1 is monday
	Day_Of_Week someDayOfMonth;//which day of week ,the 13th day of month
	int daysOfThisMonth;
	
	for(int year=yearBegin;year!=yearBegin+n;++year)
	{
		for(int month=1;month!=13;++month)
		{			
			someDayOfMonth =(firstDayOfMonth+dayNo-1)%7;
			counter[someDayOfMonth]++;
			if(month==2&&isLeapYear(year))
				daysOfThisMonth=daysOfMonth[month]+1;
			else
				daysOfThisMonth=daysOfMonth[month];

			firstDayOfMonth=(firstDayOfMonth+daysOfThisMonth)%7;			
		}
	}

	fout<<counter[6];//print saturday first
	for(int i=0;i!=6;++i)//from sunday,monday to friday
		fout<<" "<<counter[i];
	fout<<endl;
	return 0;
}
bool isLeapYear(int year)
{
	if((year%400==0)||((year%4==0)&&(year%100!=0)))
		return true;
	else return false;
}