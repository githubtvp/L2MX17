#include <iostream>
#include <string>
using namespace std;

const int NUM = 5;
void pr(string str);
void prn();
typedef string prstr;

void getTheInputNos(int *a1, int *a2, int *a3, int *a4);
int getTheLargestOfFour(int a1, int a2, int a3, int a4);

int main()
{
    int a1, a2, a3, a4;
    getTheInputNos(&a1, &a2, &a3, &a4);
    int theLargestNo = getTheLargestOfFour(a1, a2, a3, a4);
    pr("\nThe largest number is : " + to_string(theLargestNo));
    prn();
    pr("\nPS2 Qsn6 Completed!");
}

void getTheInputNos(int *a1, int *a2, int *a3, int *a4)
{
    pr("\nEnter the entries one by one : ");
    cin >> *a1 >> *a2 >> *a3 >> *a4;
}

int getTheLargestOfFour(int a1, int a2, int a3, int a4)
{
    int largest;
    if (a1 >= a2)
    { // a1 >= a2
        if (a1 >= a3)
        { // a1 > a3
            if (a1 >= a4)
            { // a1 > a4
                largest = a1;
            }
            else // a4 > a1
            {
                largest = a4;
            }
        }
        else // a3 > a1
        {
            if (a3 >= a4)
            { // a3 > a4
                largest = a3;
            }
            else // a4 > a3
            {
                largest = a4;
            }
        }
    }
    else // a2> a1
    {
        if (a2 >= a3)
        { // a2 > a3
            if (a2 >= a4)
            { // a2 > a4
                largest = a2;
            }
            else // a4 > a2
            {
                largest = a4;
            }
        }
        else // a3 > a2
        {
            if (a3 >= a4)
            { // a3 > a4
                largest = a3;
            }
            else // a4 > a3
            {
                largest = a4;
            }
        }
    }
    return largest;
}

void pr(string str)
{
    cout << str;
}

void prn()
{
    cout << endl;
}
