#include <iostream>
#include <string>
using namespace std;

const int NUM = 5;
void pr(string str);
void prn();
typedef string prstr;

void populateArray(int arr[], int *len);
void findIdx(int arr[], int aSz);

int main()
{
    int len;
    int arr[len];
    populateArray(arr, &len);
    findIdx(arr, len);
    pr("\nPS2 Qsn1 Completed!");
    prn();
}

void populateArray(int arr[], int *len)
{
    int theSize;
    pr("\nEnter no of entries for array : ");
    cin >> theSize;
    *len = theSize;
    pr("\nEnter the Array values : ");
    for (int i = 0; i < theSize; i++)
    {
        cin >> arr[i];
    }
    pr("\nArray values :");
    for (int i = 0; i < theSize; i++)
    {
        pr(to_string(arr[i]) + ",");
    }
}

void findIdx(int arr[], int aSz)
{
    int indx = 0, theNo;
    int theSize = aSz;
    pr("\nEnter the array value whose index is to be found :  ");
    cin >> theNo;
    pr("\n Number to find index of :   " + to_string(theNo));
    for (int i = 0; i < theSize; i++)
    {
        if (theNo == arr[i])
        {
            indx = i;
            pr("\nThe Element : " + to_string(arr[i]) + " exists at index : " + to_string(i) + "\n");
            return;
        }
        else if (i == (theSize - 1))
        {
            pr("\nNumber not in array\n");
        };
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
