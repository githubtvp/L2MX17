#include <iostream>
#include <string>
#include <time.h>
using namespace std;

const int MAXNO = 20;
void pr(string str);
void prn();
typedef string prstr;
void populateArr(int *arr, int aSz);
void prArray(int *arr, int aSz);

int main()
{
    srand(time(0));
    int theSz;
    pr("\nEnter the number of integers in array :  ");
    cin >> theSz;
    int *arr;
    arr = new int[theSz];
    populateArr(arr, theSz);
    prArray(arr, theSz);
    return 0;
}

void populateArr(int *arr, int aSz)
{
    int theSz = aSz;
    for (int i = 0; i < theSz; i++)
    {
        int theVal = rand() % MAXNO + 1;
        *(arr + i) = theVal;
    }
}

void prArray(int *arr, int aSz)
{
    int theSz = aSz;
    for (int i = 0; i < theSz; i++)
    {
        cout << *(arr + i) << "  ";
    }
}
void pr(string str)
{
    cout << str;
}

void prn()
{
    cout << endl;
}
