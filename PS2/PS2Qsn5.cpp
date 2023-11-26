#include <iostream>
#include <string>
using namespace std;

const int NUM = 5;
void pr(string str);
void prn();
typedef string prstr;

void populateArray(int *&arr, int *aSz);
void getTheInputNos(int *&arr, string s, string del, int aSz);
int getTheSumOfArrValues(int *arr, int aSz);
void prArrayValues(int *arr, int len);

int main()
{
    int *arr, theSize;
    populateArray(arr, &theSize);
    int theSum = getTheSumOfArrValues(arr, theSize);
    pr("\nThe Sum of all entries = " + to_string(theSum));
    prn();
    pr("\nPS2 Qsn5 Completed!");
}

void populateArray(int *&arr, int *aSz)
{
    int theSize;
    string theStr;
    pr("\nEnter the no of entries in the array : ");
    cin >> theSize;
    arr = new int[theSize];
    *aSz = theSize;
    pr("\nEnter the Array values :  ");
    cin.ignore();
    getline(cin, theStr);
    string del = " ";
    getTheInputNos(arr, theStr, del, theSize);
}

void getTheInputNos(int *&arr, string s, string del, int aSz)
{
    int theSize = aSz;
    arr = new int[theSize];
    int end = s.find(del); // Use find function to find 1st position of delimiter.
    int indx = 0;
    string str;
    while (end != -1)
    { // Loop until no delimiter is left in the string.
        str = s.substr(0, end);
        arr[indx] = stoi(str);
        indx++;
        s.erase(s.begin(), s.begin() + end + 1);
        end = s.find(del);
    }
    str = s.substr(0, end);
    arr[indx] = stoi(str);
    indx++;
}

int getTheSumOfArrValues(int *arr, int aSz)
{
    int theSize = aSz;
    int theSum = 0;
    for (int i = 0; i < theSize; i++)
    {
        theSum += arr[i];
    }
    return theSum;
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
