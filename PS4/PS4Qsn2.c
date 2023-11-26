#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
// Windows: Shift + Alt + F - for formatting

#define ARRSIZE 5
#define MAXNUM 20
#define MAXROWS 6
#define MAXCOLS 5

void populate2DArray(int rows, int cols, int (*arr)[cols]);
void printCornerElements(int rows, int cols, int (*arr)[cols];);
void printArray(int rows, int cols, int (*arr)[cols]);

int main()
{
    time_t theSeed;
    srand((unsigned)time(&theSeed));
    int nRows, mCols;
    printf("\nEnter number of Rows in the Matrix : ");
    scanf("%d", &nRows);
    printf("\nEnter number of Columns in the Matrix : ");
    scanf("%d", &mCols);
    int arr[nRows][mCols];
    populate2DArray(nRows, mCols, arr);
    printf("\nThe Array elements entered are :  \n");
    printf("\n");
    printArray(nRows, mCols, arr);
    printf("\n");
    printCornerElements(nRows, mCols, arr);
    printf("\n\n");
    return 0;
}

void populate2DArray(int rows, int cols, int (*arr)[cols])
{
    int nRows = rows;
    int mCols = cols;
     int theVal = 0;
  //  printf("\nEnter array elements row wise : \n");
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
           // int theVal2;
            theVal = rand() % MAXNUM;
            //theVal2 = rand() % 2 ;
           // if(0==theVal2) theVal = 0;
            *(*(arr + i) + j) = theVal;
           // scanf("%d", (*(arr + i) + j));
            //  *(*(arr + i) + j) = i + j + 1; // *(arr+ i) gives the address of the (i,0) element,
            // as a[i] in a 2 D array is the address of the i row
            // also same as
            //  *( arr[i] + j) = i + j;  - 'coz *(arr+i) = a[i]
        }
    }
}

void printCornerElements(int rows, int cols, int (*arr)[cols])
{
    int nRows = rows;
    int mCols = cols;
    int sum = 0;
    printf("\nCorner Elements are : ");
    printf("%d,  %d",  *(*(arr)) , *(*(arr + nRows -1) + 0) );
    printf(",  %d,  %d",  *(*(arr) + mCols -1) , *(*(arr + nRows -1) + mCols-1) );
    sum = *(*(arr));
    sum += *(*(arr + nRows -1) + 0);
    sum += *(*(arr) + mCols -1);
    sum += *(*(arr + nRows -1) + mCols-1);
    printf(",  %d", sum);
}

void printArray(int rows, int cols, int (*arr)[cols])
{
    int nRows = rows;
    int mCols = cols;
    printf("\n");
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            printf("%d\t", *(*(arr + i) + j));
        }
        printf("\n\n");
    }
}
