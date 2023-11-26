#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void pr(string str);
void prn();
typedef string prstr;

int chgCalc(int calls);
int main()
{
    int totCalls;
    int chgs;
    pr("\nEnter Total calls made : ");
    cin >> totCalls;
    chgs = chgCalc(totCalls);
    pr("\nCall charges : " + to_string(chgs) + "\n");
    return 0;
}

int chgCalc(int calls)
{
    int chgs = 0;
    int rate = 0;
    if(0==calls) return 0;
    if(calls <=99)
    {
        return 50;
    }
    else if(100 <= calls && calls <= 199)
    {
        chgs = 50 + (calls - 99) * 1;
    }
    else if(200 <= calls && calls <= 299)
    {
        chgs = 150 + (calls - 199) * 2;
    }
    else if(300 <= calls)
    {
        chgs = 350 + (calls - 299) * 3;
    }
    return chgs;
}

void pr(string str)
{
    cout << str;
}

void prn()
{
    cout << endl;
}