#include <iostream>
#include <string>
using namespace std;

const int NUM = 10;
const int POW = 3;
void pr(string str);
void prn();
typedef string prstr;

void prPwr(int aBs, int aPw);
void computeAndPrintCubes(int aLtNo, int aPow);
int main()
{
	int theLastNo = NUM;
	int thePow = POW;
	pr("\nCubes of numbers from 1 to " + to_string(theLastNo) + "\n");
	prn();
	computeAndPrintCubes(theLastNo, thePow);
	prn();
}
void computeAndPrintCubes(int aLtNo, int aPow)
{
	int theLastNo = aLtNo;
	int thePow = aPow;
	int theQt = 0;
	int theSum = 0;
	int theMul = 1;	
	prstr str;
	int curNo = 1;
	do
	{
		int curItn = thePow;
		do
		{
			theMul *= curNo;
			curItn -= 1;
		} while (curItn > 0);
		prPwr(curNo, thePow);
		pr(" = " + to_string(theMul));
		prn();
		theMul = 1;
		curNo += 1;
	} while (curNo <= 10);
}
void prPwr(int aBs, int aPw)
{
	int theBase = aBs;
	int thePwr = aPw;
	pr(to_string(theBase) + "^" + to_string(thePwr));
}
void pr(string str)
{
	cout << str;
}
void prn()
{
	cout << endl;
}
