#include <iostream>
#include <string>
using namespace std;

const int MAXLEN = 50;
void pr(string str);
void prn();
typedef string prstr;

void factorial(int n);
int  prn(int n);
int main()
{
    int n = 1;
    factorial(5);
    //prn(n);   
    pr("\nCompleted!");
}

void factorial(int n)
{
    int result = 1;
    for(int i = 1; i < n; i++)
    {
        result *= i;
    }
    cout << result;
}

int prn(int n)
{
    cout << to_string(n) << " ";
    n < MAXLEN && prn(n+1);
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
