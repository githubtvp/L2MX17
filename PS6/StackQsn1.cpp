#include <iostream>
#include <string>

using namespace std;

void push(int arrSz, int *stArr, int &sz, int &top, int item);
void pop(int arrSz, int *stArr, int &sz, int &top);

void pr(int sz, int *stArr);
int main()
{
    int arrSz = 5;
    int *stArr = new int[arrSz];
    int top = -1;
    int sz = 0;
    int item = 10;
    push(arrSz, stArr, sz, top, item);
    item = 20;
    push(arrSz, stArr, sz, top, item);
    item = 30;
    push(arrSz, stArr, sz, top, item);
    pr(sz, stArr);
    cout << "\nPop opns\n";
    pop(arrSz, stArr, sz, top);
    pr(sz, stArr);
    pop(arrSz, stArr, sz, top);
    pr(sz, stArr);
    cout << "\nTest line Stack Qsn 1";
    return 0;
}

void pop(int arrSz, int *stArr, int &sz, int &top)
{
    int itemPopped = 0;
    if (sz < 0)
    {
        cout << "\n Stack Empty ";
    }
    else
    {
        itemPopped = stArr[top--];
        sz--;
        cout << "\n Item popped : " << itemPopped;
    }
}

void push(int arrSz, int *stArr, int &sz, int &top, int item)
{
    if (sz == arrSz - 1)
    {
        cout << "\nStack overflow";
    }
    else
    {
        //     cout << "\nPush item : " << item;
        stArr[sz++] = item;
        //  cout <<"\nItem in array : "<< stArr[sz-1];
        top++;
    }
}

void pr(int sz, int *stArr)
{
    for (int i = 0; i < sz; i++)
    {
        cout << "\n " << *(stArr + i);
    }
}
