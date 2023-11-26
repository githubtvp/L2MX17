#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void pr(string str);
void prn();
typedef string prstr;

int main()
{
    int noOfPens;
    pr("\nEnter number of pens to place in stand : ");
    cin >> noOfPens;
    pr("\nYou entered " + to_string(noOfPens) + " pens to place in stand");
    if (noOfPens > 5)
        pr("\n\nPen stand full! ");
    pr("\n\nCompleted Qsn 1\n\n");
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