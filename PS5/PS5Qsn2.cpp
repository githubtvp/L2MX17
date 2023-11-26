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
void sortArr(int *arr, int aSz);
void swap(int *arr, int swIn, int curIn);
bool findElementInArr(int *arr, int stInd, int lsId, int aNo);

int main()
{
    srand(time(0));
    int theSz, theTgt;
    pr("\nEnter the number of integers in array(<=20) :  ");
    cin >> theSz;
    int *arr;
    arr = new int[theSz];
    populateArr(arr, theSz);
    prArray(arr, theSz);
    sortArr(arr, theSz);
    pr("\nSorted array : \n");
    prArray(arr, theSz);
    pr("\nEnter the target number to be found :  ");
    cin >> theTgt;
    int stIndx = 0;
    int lsIndx = theSz - 1;
    //   int theNo = MAXNO - 5;
    if (findElementInArr(arr, stIndx, lsIndx, theTgt))
    {
        pr("\nFound!");
    }
    else
    {
        pr("\nNot Found!");
    }
    return 0;
}

bool findElementInArr(int *arr, int stId, int lsId, int aNo)
{
    int stIndx = stId;
    int lsIndx = lsId;
    int theNo = aNo;
    bool found = true;
    if (lsIndx <= stIndx)
    {
        found = false;
        return found;
    }
    int midPt = (lsIndx + stIndx) / 2;
    if (theNo == arr[midPt] || theNo == arr[midPt + 1])
    {
        found = true;
        return found;
    }
    else if (theNo < arr[midPt])
    {
        lsIndx = midPt;
    }
    else if (theNo > arr[midPt])
    {
        stIndx = midPt + 1;
    }
    found = findElementInArr(arr, stIndx, lsIndx, theNo);
    return found;
}

void sortArr(int *arr, int aSz)
{
    int theSz = aSz;
    int theSwapIndx = 0;
    for (int i = 0; i < theSz - 1; i++)
    {
        theSwapIndx = i;
        for (int j = i + 1; j < theSz; j++)
        {
            if (arr[theSwapIndx] > arr[j])
            {
                theSwapIndx = j;
            }
        }
        if (i != theSwapIndx)
        {
            swap(arr, theSwapIndx, i);
        }
    }
}

void swap(int *arr, int swIn, int curIn)
{
    int theSwapIndx = swIn;
    int theCurIndx = curIn;
    int temp = 0;
    temp = arr[theCurIndx];
    arr[theCurIndx] = arr[theSwapIndx];
    arr[theSwapIndx] = temp;
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
