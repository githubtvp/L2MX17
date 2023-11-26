#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void pr(string str);
void prn();
typedef string prstr;

int main()
{
    int age;
    pr("\nEnter your age : ");
    cin >> age;
    if (age >= 18)
        pr("\nEligible to vote");
    else
        pr("\nNot eligible to vote");
    pr("\n\nCompleted Qsn 3\n");
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
