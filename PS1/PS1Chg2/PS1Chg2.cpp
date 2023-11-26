#include <iostream>
#include <string>
using namespace std;

const int NUM = 5;
void pr(string str);
void prn();
typedef string prstr;

int convertToOdd(int aNo);
void printSeries(int aNo, int lnNo);
void printFirstLastLine(int aNo);
void prOtherLines(int aNo, int lnNo, int mSp);
void printDecrInc(int stNo, int endNo, bool decr);
void prMidNos(int aNo, int nCnt);

int main()
{
	int theMaxNo = NUM;
	theMaxNo = convertToOdd(theMaxNo);
	prn();
	int theLnNo = 1;
	printSeries(theMaxNo, theLnNo);
	prn();
}

int convertToOdd(int aNo)
{
	int theNo = aNo;
	if (0 == (theNo % 2) && (4 <= theNo && theNo <= 10))
	{
		return (theNo - 1);
	}
	else if (theNo <= 3 || theNo > 10)
	{
		return 3;
	}
	return theNo;
}

void printSeries(int aNo, int lnNo)
{
	int theMaxNo = aNo;//5
	int theLnNo = lnNo;
	int theMaxPr = 2 * theMaxNo - 1;//9 digits
	int midSpace = 0;
	int stNo = theMaxNo, endNo;
	endNo = theMaxNo - theLnNo;//5 -1 =4
	midSpace = theMaxPr - 4;
	printFirstLastLine(theMaxNo);
	do {
		prOtherLines(stNo, theLnNo, midSpace);
		theLnNo += 1;
		midSpace -= 2;
	} while (theLnNo < theMaxNo);
	theLnNo = theMaxNo -2;
	midSpace = 1;
	do {
		prOtherLines(stNo, theLnNo, midSpace);
		theLnNo -= 1;
		midSpace += 2;
	} while (theLnNo > 0);
	prn();
	printFirstLastLine(theMaxNo);
}

void printFirstLastLine(int aNo)
{
	int theNo = aNo;
	int theItn = 2 * theNo - 1;
	do
	{
		pr(to_string(theNo));
		theItn -= 1;
	} while (theItn > 0);
}

void prOtherLines(int aNo, int lnNo, int mSp)
{
	int theMaxNo = aNo;//5
	int theLnNo = lnNo;
	int midSpace = mSp;
	int stNo = theMaxNo;
	int endNo = stNo - theLnNo;//5 -1 =4
	prn();
	printDecrInc(stNo, endNo, true);//5, 4
	prMidNos(endNo, midSpace);
	if (endNo == 1) endNo += 1;
	printDecrInc(stNo, endNo, false);
}

void printDecrInc(int stNo, int endNo, bool decr)
{
	int theStNo = stNo;
	int theEndNo = endNo;
	if (decr)//true
	{
		for (int i = theStNo; i >= theEndNo; i--)//5, 4
		{
			pr(to_string(i));
		}
	}
	else {
		for (int i = theEndNo; i <= theStNo; i++)
		{
			pr(to_string(i));
		}
	}
}

void prMidNos(int aNo, int nCnt)
{
	int theNo = aNo;
	int theCnt = nCnt;
	for (int i = 0; i < theCnt; i++)
	{
		pr(to_string(theNo));
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



