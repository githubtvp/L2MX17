#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void pr(string str);
void prn();
typedef string prstr;

int main()
{
    int age, wt;
    pr("\nEnter your age : ");
    cin >> age;
    pr("\nEnter your weight : ");
    cin >> wt;
    if ((18 < age && age < 55) && (wt > 45))
    {
        pr("\nEligible to donate. ");
    }
    else
    {
        pr("\nNot Eligible to donate.");
    }
    pr("\n\nCompleted Qsn 2\n\n");
    return 0;
}

void pr(string str)
{
    cout << str;
}

void prn()
{
    cout << endl;
}
