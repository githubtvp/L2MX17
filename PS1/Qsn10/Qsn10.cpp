#include <iostream>
#include <string>

using namespace std;
void pr(string str);
void prn();
typedef string prstr;

void prPwr(int aBs, int aPw);
void computeGeoMetProgSum(int aBs, int aMxExp);

int main()
{
	int theBase, theMaxExp;
	pr("\nEnter the value X for Base : ");
	cin >> theBase;
	pr("\nEnter the value N for Exponent : ");
	cin >> theMaxExp;
	computeGeoMetProgSum(theBase, theMaxExp);
	prn();
}
void computeGeoMetProgSum(int aBs, int aMxExp)
{
	int theBase = aBs, theMaxExp = aMxExp;
	int theGSum = 1;
	int theXMul = 1;
	int theTermNo = 1;
	prstr str;
	if (0 == theBase && 0 == theMaxExp)
	{
		pr("\n0 to Power 0 is undefined ...\n Quitting..\n");
		return;
	}
	else if (0 == theMaxExp)
	{
		theGSum = 2;
	}
	else
	{
		do
		{
			int theCurPwrItn = theTermNo;
			do
			{
				theXMul *= theBase; // 1. base 5, 1*5,  2.
				theCurPwrItn -= 1;
			} while (theCurPwrItn > 0);
			theTermNo += 1;
			theGSum += theXMul;
			theXMul = 1;
		} while (theTermNo <= theMaxExp);
	}
	str = "\nThe value X for Base : " + to_string(theBase);
	pr(str);
	str = "\nThe value N for Exponent : " + to_string(theMaxExp);
	pr(str);
	prn();
	pr("\nThe Geometric Proggression series is : ");
	prn();
	pr("1");
	if (0 == theMaxExp)
	{
		pr(" + ");
		prPwr(theBase, 0);
	}
	else
	{
		int theIncrExp = 1;
		do
		{
			if (theIncrExp > 5)
			{
				pr("........ + ");
				theIncrExp = theMaxExp;
			}
			else
			{
				pr(" + ");
			}			
			prPwr(theBase, theIncrExp);						
			theIncrExp += 1;
		} while (theIncrExp <= theMaxExp);
	}
	str = "\nSum of the Geometric Progression is : " + to_string(theGSum);
	pr(str);
	prn();
}
void prPwr(int aBs, int aPw)
{
	int theBase = aBs;
	int thePwr = aPw;
	if (0 == thePwr)
	{
		pr("1");
	}
	else if (1 == thePwr)
	{
		pr(to_string(theBase));
	}
	else
	{
		pr(to_string(theBase) + "^" + to_string(thePwr));
	}
}

void pr(string str)
{
	cout << str;
}

void prn()
{
	cout << endl;
}
