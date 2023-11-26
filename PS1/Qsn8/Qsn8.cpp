#include <iostream>
#include <string>

using namespace std;
void pr(string str);
void prn();
typedef string prstr;

void computeNos();

int main()
{
	computeNos();
	prn();
}

void computeNos()
{
	int theNo;
	int theRem = 0;
	int theQt = 0;
	int theSum = 0;
	int theMul = 1;
	prstr str;
	pr("\nEnter a No : ");
	cin >> theNo;
	do
	{
		theRem = theNo % 10;
		theQt = theNo / 10;
		theSum += theRem;
		theMul *= theRem;
		str = to_string(theRem);
		pr(str);
		theNo = theQt;
	} while (theNo > 0);
	str = "\nThe Sum of each digit = " + to_string(theSum);
	pr(str);
	str = "\nThe Multiplication of each digit = " + to_string(theMul);
	pr(str);
}

void pr(string str)
{
	cout << str;
}

void prn()
{
	cout << endl;
}
