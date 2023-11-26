#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
void pr(string str);
void prn();
typedef string prstr;

void getInputNumbers();

int main()
{
	getInputNumbers();
	prstr str = "\nCompleted Qsn 7";
	pr(str);
	prn();
}

void getInputNumbers()
{
	float theNo = 0;
	int theTotCnt = 0;
	int thePosCnt = 0;
	int theNegCnt = 0;
	float thePosTot = 0, theNegTot = 0, theTotal = 0;
	pr("\nEnter series of positive and/or negative numbers, enter 0 to end entries \n");
	do
	{
		cin >> theNo;
		if (0 == theNo && 0 == theTotCnt)
		{
			pr("\nNo valid entries...Quitting!");
			return;
		}
		else if (theNo > 0)
		{
			thePosCnt += 1;
			thePosTot += theNo;
		}
		else if (theNo < 0)
		{
			theNegCnt += 1;
			theNegTot += theNo;
		}
		theTotCnt = thePosCnt + theNegCnt;
		theTotal = thePosTot + theNegTot;
	} while (theNo != 0);

	pr("\nTotal Positive entries :" + to_string(thePosCnt));
	pr("\nTotal Negative entries :" + to_string(theNegCnt));
	pr("\nTotal entries :" + to_string(theTotCnt));
	prn();
	cout << fixed << showpoint;
	cout << setprecision(2);
	pr("\nTotal of Positive entries :" + to_string(thePosTot));
	pr("\nTotal of Negative entries :" + to_string(theNegTot));
	pr("\nTotal of all entries :" + to_string(theTotal));
	prn();
}

void pr(string str)
{
	cout << str;
}

void prn()
{
	cout << endl;
}
