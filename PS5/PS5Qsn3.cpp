#include <iostream>
#include <string>
#include <time.h>

using namespace std;

const int MAXNO = 9;

void populateArr(int **arr, int mRw, int nCl);
void prArr(int **arr, int mRw, int nCl);
void prOuter(int **arr, int mRw, int nCl, int stRw, int stCl);
void prPattern(int **arr, int mRw, int nCl);

int main()
{
    srand(time(0));
    int mRows, nCols;
    cout << "Enter the no of rows :  ";
    cin >> mRows;
    cout << "Enter the no of cols :  ";
    cin >> nCols;
    int **arr;
    arr = new int *[mRows];
    for (int i = 0; i < mRows; i++)
    {
        arr[i] = new int[nCols];
    }
    populateArr(arr, mRows, nCols);
    prArr(arr, mRows, nCols);
    cout << "\nPrinting outer rows \n";
    /*int curRow = 0;
    int curCol = 0;
    int rowSz = mRows;
    int colSz = nCols;
    prOuter(arr, rowSz, colSz, curRow, curCol);
    */
    prPattern(arr, mRows, nCols);

    return 0;
}

void prPattern(int **arr, int mRw, int nCl)
{
    int curRow = 0;
    int curCol = 0;
    int rowSz = mRw;
    int colSz = nCl;
    int theLastRow = mRw;
    int theLastCol = nCl;
    int theMidRow = rowSz / 2;
    // if(0!=rowSz%2)
    // {
    // theMidRow+=1;
    // }
    //  cout << "\nCur Row : "<<curRow<<"  CurCol : "<<curCol <<endl<<endl;
    //  prOuter(arr, rowSz, colSz, curRow, curCol);
    for (int i = 0, j = 0; curRow <= theMidRow;)
    {
        prOuter(arr, rowSz, colSz, curRow, curCol);
        curRow += 1;
        curCol += 1;
        rowSz -= 1;
        colSz -= 1;
        if ( (curRow == theMidRow ) && (curCol < colSz) ) 
        {
           // curCol -= 1;
            cout << "curCol :  " <<curCol;
            cout << "  ColSz : " <<colSz;
        } 

      //  cout << "\n\nCur Row : "<<curRow<<"  CurCol : "<<curCol << "  theMidRow : "<< theMidRow << endl;
       //         cout << "\nRow Sz : "<<rowSz<<"  colSz : "<<colSz << endl;

    }
}

void prOuter(int **arr, int mRw, int nCl, int stRw, int stCl)
{
    int stRow = stRw;
    int stCol = stCl;
    int mRows = mRw;
    int nCols = nCl;
    // pr top row
      cout <<endl <<"before for loop "<<endl<<endl;
    int i = stRow;
    for (int j = stCol; j < nCols; j++)
    {

        cout << arr[i][j] << "  ";
    }
    // cout <<endl;
    // pr rt Col
    int j = nCols - 1;
    for (int i = stRow + 1; i < mRows; i++)
    {

        cout << arr[i][j] << "  ";
    }

    // pr bot row
    //  cout <<endl;
    i = mRows - 1;
    for (int j = nCols - 2; j >= stCol; j--)
    {
        cout << arr[i][j] << "  ";
    }

    // cout <<endl;
    // pr lt Col
    j = stCol;
    for (int i = mRows - 2; i > stRow; i--)
    {

        cout << arr[i][j] << "  ";
    }

    //  cout <<endl;
}

void populateArr(int **arr, int mRw, int nCl)
{
    int mRows = mRw;
    int nCols = nCl;
    for (int i = 0; i < mRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            int theVal = rand() % MAXNO + 1;
            arr[i][j] = theVal;
        }
    }
}

void prArr(int **arr, int mRw, int nCl)
{
    int mRows = mRw;
    int nCols = nCl;
    for (int i = 0; i < mRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            cout << arr[i][j] << "\t"; // new int[nCols];
        }
        cout << "\n";
    }
}
