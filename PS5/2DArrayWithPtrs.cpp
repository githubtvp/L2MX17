#include <iostream>
#include <string>
#include <time.h>
using namespace std;

const int MAXNUM = 10;
const string WHITESPACE = " ";
void pr(string str);
void prn();
typedef string prstr;

void populate2DArray(int **aMx, int rows, int cols);
void printArray(int **aMx, int rows, int cols);

int main()
{
    srand(time(0));
    int nRows, mCols;
    int **theMx;
    pr("\nEnter number of Rows in the Matrix : ");
    cin >> nRows;
    pr("\nEnter number of Columns in the Matrix : ");
    cin >> mCols;
    theMx = new int *[nRows];//declare and initialize the rows pointer arrays
    for (int i = 0; i < nRows; i++)
    {
        theMx[i] = new int[mCols];// declare the size of each row pointer
    }
    populate2DArray(theMx, nRows, mCols);
   
    pr("\nThe Array elements entered are :  \n");
    pr("\n");
    printArray(theMx, nRows, mCols);
    prn();
    pr("\nPS4 Qsn3 Completed!");
}

void populate2DArray(int **aMx, int rows, int cols)
{
    int nRows = rows;
    int mCols = cols;
    int theVal = 0;
    pr("\nEnter array elements row wise : \n");   
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

void pr(string str)
{
    cout << str;
}

void prn()
{
    cout << endl;
}
