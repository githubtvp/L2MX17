#include <iostream>
#include <string>
using namespace std;

const int NUM = 5;
void pr(string str);
void prn();
typedef string prstr;

void printSeries(int aNo);

int main()
{
	int theMaxNo = NUM;
	printSeries(theMaxNo);
	pr("\nPrint Pattern Completed!");
	prn();
}

void printSeries(int aNo)
{
	int theMaxNo = aNo;
	int curNo = 1;
	while (curNo <= theMaxNo)
	{
		int curItn = 1;
		do
		{
			prstr str = to_string(curItn) + " ";
			pr(str);
			curItn += 1;
		} while (curItn <= curNo);
		curNo += 1;
		prn();
	};
}

void pr(string str)
{
	cout << str;
}

void prn()
{
	cout << endl;
}
