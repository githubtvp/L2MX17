// skeCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
void pr(string str);
void prn();
typedef string prstr;

int main()
{
	prstr str = "Test line : Hello World!";
	pr(str);
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



