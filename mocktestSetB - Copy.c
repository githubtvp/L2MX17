#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>

#define MAXSIZE 5
void populateArray(int aSz, int arr[aSz]);
void prArray(int *arr, int aSz);
void findTaget(int *arr, int aSz, int aNo);
void sortArr(int *arr, int aSz);
void swapEl(int *arr, int posn1, int posn2);
void pivotAt(int *arr, int aSz, int aPt);

int main()
{
    int theSz;
    printf("\nEnter the array size : ");
    scanf("%d", &theSz);
    int arr[theSz];
    populateArray(theSz, arr);
    sortArr(arr, theSz);
    printf("\nAfter sort\n");
    prArray(arr, theSz);
    int thePvtPt; // = 3;
    printf("\nEnter the Index No to Pivot on \n");
    scanf("%d", &thePvtPt);
    pivotAt(arr, theSz, thePvtPt);
    int theNo; // = 6;
    printf("\nEnter the Target no to be searched .. ");
    scanf("%d", &theNo);
    findTaget(arr, theSz, theNo);
    return 0;
}

void pivotAt(int *arr, int aSz, int aPt)
{
   int thePvtPt = aPt;
    int theSz = aSz;
    int arr2[thePvtPt];
    for(int i = 0; i < thePvtPt; i++)
    {
        arr2[i] = arr[i];
    }
    for(int i = 0, j = thePvtPt; j < theSz; i++, j++)
    {
        arr[i] = arr[j];
    }
    int theStPt = theSz - thePvtPt;
    for(int i = theStPt, j = 0; i < theSz; i++, j++)
    {
        arr[i] = arr2[j];
    }
    printf("\nAfter Pivoting\n");
    prArray(arr, theSz);
}

void sortArr(int *arr, int aSz)
{
    int theSz = aSz;
    int theCurEl = 0;
    int theSwapIndx = 0;
    for (int i = 0; i < theSz-1; i++)
    {
        theCurEl = arr[i];
        theSwapIndx = i;
        for (int j = i+1; j < theSz; j++)
        {
            if(arr[theSwapIndx] > arr[j])
            {
                theSwapIndx = j;
            }
        }
        if(i != theSwapIndx)
        {
            swapEl(arr, i , theSwapIndx);
        }
    }
}

void swapEl(int *arr, int posn1, int posn2)
{
    int temp = 0;
    temp = arr[posn1];
    arr[posn1] = arr[posn2];
    arr[posn2] = temp;
}

void populateArray(int aSz, int arr[aSz])
{
    int theSz = aSz;
    printf("\nEnter the array elements : \n");
    for (int i = 0; i < theSz; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void prArray(int *arr, int aSz)
{
    int theSz = aSz;
    printf("\nThe array elements are : \n");
    for (int i = 0; i < theSz; i++)
    {
        printf("%d,   ", arr[i]);
    }
}

void findTaget(int *arr, int aSz, int aNo)
{
    int theSz = aSz;
    int indx = 0;
    int theNo = aNo;
    bool notFound = true;
    for (int i = 0; i < theSz && notFound; i++)
    {
        if(theNo == arr[i])
        {
            printf("\nFound");
            notFound = false;
            printf("\nTraget No : %d found at Index : %d", arr[i], i);
        }
    }
    if(notFound)
    {
        printf("\nThe target not found\n");
        printf("\nOutput : -1");
    }
}
