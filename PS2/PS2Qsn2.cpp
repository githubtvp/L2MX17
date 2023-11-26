#include <iostream>
#include <string>
using namespace std;

const int NUM = 5;
void pr(string str);
void prn();
typedef string prstr;

void populateArray(int arr[], int *len);
void findMaxMin(int arr[], int aSz, int *max, int *min);
void prArrayValues(int arr[], int len);

int main()
{
    int len;
    int arr[] = {23, 24, 3, 45, 10, 6, 3};
    len = sizeof(arr) / sizeof(int);
    prArrayValues(arr, len);
    int min, max;
    findMaxMin(arr, len, &max, &min);
    pr("\nMaximum number in the array : " + to_string(max));
    pr("\nMinimum number in the array : " + to_string(min));
    pr("\nPS2 Qsn2 Completed!");
    prn();
}

void populateArray(int arr[], int *len)
{
    int theSize;
    pr("\nEnter no of entries for array : ");
    cin >> theSize;
    *len = theSize;
    pr("\nEnter the Array values :  ");
    for (int i = 0; i < theSize; i++)
    {
        cin >> arr[i];
    }
    pr("\nArray values :  ");
    for (int i = 0; i < theSize; i++)
    {
        pr(to_string(arr[i]) + ",");
    }
}

void prArrayValues(int arr[], int len)
{
    int theSize = len;
    pr("\nArray values :  ");
    for (int i = 0; i < theSize; i++)
    {
        pr(to_string(arr[i]) + ",");
    }
}

void findMaxMin(int arr[], int aSz, int *max, int *min)
{
    int theSize = aSz;
    int maxNo = arr[0], minNo = arr[0];
    for (int i = 0; i < theSize; i++)
    {
        // pr("\nMaximum number in the array : " + to_string(maxNo));
        if (maxNo < arr[i])
        {
            maxNo = arr[i];
            // pr("\n Cur Max No : " + to_string(maxNo));
        }
        // pr("\nArr Val being tested : " + to_string(arr[i]) + " against Min value : " + to_string(minNo));
        if (minNo > arr[i])
        {
            minNo = arr[i];
        }
    }
    *max = maxNo;
    *min = minNo;
}
void pr(string str)
{
    cout << str;
}

void prn()
{
    cout << endl;
}
