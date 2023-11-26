#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void pr(string str);
void prn();
typedef string prstr;

int main()
{
    double cMk, wMk;
    double aggPct;
    pr("\nEnter Course Wk marks(0 to 50) : ");
    cin >> cMk;
    pr("\nEnter Written Wk marks(0 to 50) : ");
    cin >> wMk;
    aggPct = cMk + wMk;
    cout << fixed << setprecision(1);
    prn();
    if (aggPct >= 45)
    {
        if ((cMk < 20) || (wMk < 20))
        {
            pr("\nFailed : Result(moderated) : 45%");
        }
        else
        {
            pr("\nPassed : Result : " + to_string(aggPct));
        }
    }
    else
    {
        pr("\nFailed : Result : " + to_string(aggPct));
    }
    pr("\n\nCompleted Qsn 4\n");
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
