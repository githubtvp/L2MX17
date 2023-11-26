#include <iostream>
#include <string>
#include <time.h>
using namespace std;

const int MAXNUM = 9;
const string WHITESPACE = " ";
void pr(string str);
void prn();
typedef string prstr;

const int NCOLS = 5;
void shiftRowsAndCols(int **aMx, int aSz, int rows, int cols, bool itn1);
void populate2DArray(int **aMx, int rows, int cols);
void printArray(int **aMx, int rows, int cols);
void prArray(int aMx[][NCOLS], int rows, int cols);

int main()
{
    srand(time(0));
    int nRows, mCols;
    pr("\nEnter number of Rows in the Matrix : ");
    cin >> nRows;
    pr("\nEnter number of Columns in the Matrix : ");
    cin >> mCols;
    int **theMx;
    theMx = new int *[nRows];
    for (int i = 0; i < nRows; i++)
    {
        theMx[i] = new int[mCols];
    }
    populate2DArray(theMx, nRows, mCols);
    pr("\n1. The Array elements entered are :  \n");
    pr("\n");
    printArray(theMx, nRows, mCols);
    prn();
    int theSz = nRows;
    int theSqSz = theSz;
    int theCorRow = 0;
    int theCorCol = 0;
    bool itn1 = true;  
    while (theSqSz >= 2)
    {
        shiftRowsAndCols(theMx, theSqSz, theCorRow, theCorCol, itn1);     
        theCorRow++;        
        theCorCol++;
        itn1 = false;
        theSqSz -= 2;     
    } // end do while
    pr("\n\n2. The Array elements after shift :  \n");
    pr("\n");
    printArray(theMx, nRows, mCols);
    prn();
    pr("\nPS5 Qsn1 Completed!");
}

void shiftRowsAndCols(int **aMx, int sqSz, int corRow, int corCol, bool itn1)
{
    int theCorRow = corRow;
    int theCorCol = corCol;
    int theSqSz = sqSz;
    int shiftCnt = theSqSz;
    do
    {
        theSqSz = sqSz;
        if (itn1)
        {
            theSqSz -= 1;
        }
        int theReplaceVal = aMx[theCorRow][theCorCol]; //(0, 0)
        int theVerStRow = theCorRow + 1;               // 1
        int theHorReplaceCol = corCol + 1;
        // leftmost Ver col shifted UP starting from theVerStRow
        for (int curRow = theVerStRow; curRow <= theSqSz; curRow++)
        {
            aMx[curRow - 1][theCorCol] = aMx[curRow][theCorCol];          
        }
        //  last row shift one left starting from 2nd coln
        for (int curCol = theCorCol + 1; curCol <= theSqSz; curCol++) // 2, 1
        {
            aMx[theSqSz][curCol - 1] = aMx[theSqSz][curCol];           
        }
        // rightmost Ver col shifted DOWN starting from last but 1 row
        for (int curRow = theSqSz; curRow > theCorRow; curRow--)
        {
            aMx[curRow][theSqSz] = aMx[curRow - 1][theSqSz];            
        }
        // first row shift one right starting from last but 1 col
        for (int curCol = theSqSz; curCol > theCorCol; curCol--) // 2, 1
        {
            aMx[theCorRow][curCol] = aMx[theCorRow][curCol - 1];           
        }
        aMx[theCorRow][theHorReplaceCol] = theReplaceVal; // row 2, col last
        shiftCnt -= 1;
    } while (shiftCnt > 1);
}

void populate2DArray(int **aMx, int rows, int cols)
{
    int nRows = rows;
    int mCols = cols;
    int theVal = 0;
    //  pr("\nEnter array elements row wise : \n");
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            int theVal;
            theVal = rand() % MAXNUM + 1;
            aMx[i][j] = theVal;
        }
    }
}

void printArray(int **aMx, int rows, int cols)
{
    int nRows = rows;
    int mCols = cols;
    prn();
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            cout << aMx[i][j] << "\t";
        }
        prn();
    }
}

void prArray(int aMx[][NCOLS], int rows, int cols)
{
    int nRows = rows;
    int mCols = cols;
    prn();
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            cout << aMx[i][j] << "\t";
        }
        prn();
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
