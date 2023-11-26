#include <iostream>
#include <string>
using namespace std;

const int NUM = 5;
void pr(string str);
void prn();
typedef string prstr;

int convertToEven(int *aNo);
void processHalfArrayValues(int *arr, int aSz);
void addBalVal(int *&arr, int aSz, int aVal);

void populateArray(int *&arr, int *aSz);
void prArrayValues(int *arr, int len);

int main()
{
    int *arr, theSize;
    populateArray(arr, &theSize);
    pr("\nArray values are : ");
    prArrayValues(arr, theSize);
    pr("\nThe two Half arrays are : ");
    processHalfArrayValues(arr, theSize);
    pr("\nArray values after balancing : ");
    prArrayValues(arr, theSize);
    pr("\nPS2 Qsn4 Completed!");
    prn();
}

void populateArray(int *&arr, int *aSz)
{
    int theSize;
    pr("\nEnter a Even number as the no of entries for array : ");
    cin >> theSize;
    theSize = convertToEven(&theSize);
    arr = new int[theSize];
    *aSz = theSize;
    pr("\nEnter the Array values :  ");
    for (int i = 0; i < theSize; i++)
    {
        cin >> arr[i];
    }
}

int convertToEven(int *aNo)
{
    if (0 == *aNo % 2)
    {
        return *aNo;
    }
    else
    {
        return *aNo + 1;
    }
}

void processHalfArrayValues(int *arr, int aSz)
{
    int theSize = aSz;
    int fiSum = 0, seSum = 0;
    pr("\nFirst Array values :  ");
    for (int i = 0; i < theSize / 2; i++)
    {
        pr(to_string(arr[i]) + ",");
        fiSum += arr[i];
    }
    pr("\nSecond Array values :  ");
    for (int i = theSize / 2; i < theSize; i++)
    {
        pr(to_string(arr[i]) + ",");
        seSum += arr[i];
    }
    pr("\nFirst Sum : " + to_string(fiSum));
    pr("\nSecond Sum : " + to_string(seSum));
    int diff = fiSum - seSum;
    if (0 != diff)
    {
        pr("\nThe two Half arraya are not balanced!");
        pr("\nThe smallest positive value to balance the arrays is : " + to_string(abs(diff)));
        addBalVal(arr, theSize, diff);
    }
    else
    {
        pr("\nThe two Half arraya are balanced!");
    }
}

void addBalVal(int *&arr, int aSz, int aVal)
{
    int theSize = aSz;
    int theBalVal = aVal;
    if (theBalVal < 0)
    {
        arr[0] += -1 * theBalVal;
    }
    else
    {
        arr[theSize / 2] += theBalVal;
    }
}
void prArrayValues(int *arr, int aSz)
{
    int theSize = aSz;
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
