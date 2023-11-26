#include <iostream>
#include <string>
using namespace std;

const int NUM = 5;
void pr(string str);
void prn();
typedef string prstr;

void doLeftShift(int *&arr, int len, int aSh);
void populateArray(int *&arr, int *len);
void prArrayValues(int *arr, int len);

int main()
{
    int *arr, theSize, theOrigSh, theSh;
    populateArray(arr, &theSize);
    pr("\nEnter the no of left shifts to be done : ");
    cin >> theOrigSh;
    prArrayValues(arr, theSize);
    theSh = theOrigSh % theSize;
    doLeftShift(arr, theSize, theSh);
    pr("\nUpdated Array after " + to_string(theOrigSh) + " Left shifts");
    prArrayValues(arr, theSize);
    pr("\nPS2 Qsn3 Completed!");
    prn();
}

void doLeftShift(int *&arr, int len, int aSh)
{
    int *shArr;
    int theShift = aSh;
    int theSize = len;
    shArr = new int[aSh];
    for (int i = 0; i < theShift; i++)
    {
        shArr[i] = arr[i];
    }
    for (int i = 0; i < theSize - theShift; i++)
    {
        arr[i] = arr[i + theShift];
    }
    int lastPt = theSize - theShift;
    for (int i = 0; i < theShift; i++, lastPt++)
    {
        arr[lastPt] = shArr[i];
    }
}

void populateArray(int *&arr, int *len)
{
    int theSize;
    pr("\nEnter the no of entries for array : ");
    cin >> theSize;
    arr = new int[theSize];
    *len = theSize;
    pr("\nEnter the Array values :  ");
    for (int i = 0; i < theSize; i++)
    {
        cin >> arr[i];
    }
}

void prArrayValues(int *arr, int len)
{
    int theSize = len;
    pr("\nArray values :  ");
    for (int i = 0; i < theSize; i++)
    {
        pr(to_string(arr[i]) + ",");
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
