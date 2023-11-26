#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void pr(string str);
void prn();
typedef string prstr;
const int STARTNO = 7;
const int ENDNO = 100;
void chkNo(int stNo, int endNo);
bool div5and6(int aNo);

int main()
{
	int theStartNo = STARTNO;
	int theEndNo = ENDNO;
	pr("\nThe Start No  ; " + to_string(theStartNo) + ", the End No : " + to_string(theEndNo));
	prn();
	chkNo(theStartNo, theEndNo);
	return 0;
}
void chkNo(int stNo, int endNo)
{
	int theStartNo = stNo;
	int theEndNo = endNo;
	bool found = false;
	do
	{
		theStartNo += 1;
		if (0 == theStartNo % 4)
		{
			if (div5and6(theStartNo))
			{
				found = true;
				pr("\nThe No : " + to_string(theStartNo) + " meets the conditions\n\n");
			}
		}
	} while (theStartNo <= theEndNo);
}
bool div5and6(int aNo)
{
	int rem5, rem6;
	int theNo = aNo;
	rem5 = theNo % 5;
	rem6 = theNo % 6;
	if (4 == rem5 && 4 == rem6)
		return true;
	return false;
}
void pr(string str)
{
	cout << str;
}
void prn()
{
	cout << endl;
}