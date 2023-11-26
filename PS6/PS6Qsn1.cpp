#include <iostream>
#include <string>

using namespace std;

void display(int *st, int sz);
void populateStack(int *st, int sz, int &stTop);
int getTop(int *st, int stTop);
void popTop(int *st, int &sz, int &stTop, int *popSt, int &popSz);
bool foundInPopSt(int aNo, int *popSt, int &popSz);
void push(int *st, int &sz, int &stTop, int aNo);

int countPopsReqd(int aNo, int *popSt, int &popSz, int *st, int &sz, int &top);

int stTop = 0;
int stSz = 0;

int main()
{
    int sz;
    //  cout <<"\nEnter no of elements in stack"<<endl;
    //  cin >> sz;
    sz = 6;
    int stTop = sz - 1;
    int *arrSt;
    arrSt = new int[sz];
    arrSt[0] = {1};
    arrSt[1] = {2};
    arrSt[2] = {3};
    arrSt[3] = {4};
    arrSt[4] = {6};
    arrSt[5] = {8};
    int *elOrder = new int[sz];
    elOrder[0] = {2};
    elOrder[1] = {1};
    elOrder[2] = {4};
    elOrder[3] = {3};
    elOrder[4] = {8};
    elOrder[5] = {6};
    int *popSt = new int[sz];
    int popSz = 0;
    int aNo = 8;
   // push(arrSt, sz, stTop, aNo);
    //   populateStack(arrSt, sz, stTop);
    cout <<"\nArr el : ";
    display(arrSt, sz);
    cout <<"\nEl order : ";    
    display(elOrder, sz);
    //  popTop(arrSt, sz, stTop, popSt, popSz);
    // display(arrSt, sz);
    for (int i = sz - 1; i >= 0; i--)
    {
        aNo = elOrder[i];
        //cout << "\n theNo : " << aNo << " index : "<< i;
        int popCnt = countPopsReqd(aNo, popSt, popSz, arrSt, sz, stTop);
        cout << " \nPop cnt reqd for : "<< aNo << " is : " << popCnt <<endl;
    }
    cout << "\n\n---End Test line ---";
    return 0;
}

int countPopsReqd(int aNo, int *popSt, int &popSz, int *st, int &sz, int &stTop)
{
    int popReqd = 0;
    if (foundInPopSt(aNo, popSt, popSz))
    {
        popReqd = 0;
        // cout<<"\nFound in popStack : "<<aNo << "\n";
    }
    else if (aNo == st[stTop])
    {
        popReqd = 1;
        cout<<"\npopReqd is 1 : "<<aNo << "\n";
    }
    else
    { // search arrSt
        while ((aNo != st[stTop]) && (sz != 0))
        {
            cout <<"\nPop top el : " << st[stTop] << "  \n";
            popTop(st, sz, stTop, popSt, popSz);
            popReqd++;
        }
        if (sz <= 0)
        {
            popReqd = 0;
            //  cout<<"\nNot Found in popStack : "<<aNo << "\n";
        }
        else{
            popReqd++;
            popTop(st, sz, stTop, popSt, popSz);
        }
    }
    //   cout << "\nPop count for element : " << aNo << " is : " << popReqd <<endl;
    return popReqd;
}

void popTop(int *st, int &sz, int &stTop, int *popSt, int &popSz)
{
    //  cout << "\nTop El : " << st[sz - 1] << " popped out \n\n";

    //(stackSize-1 = stackTop)
    // on pop from stack add that element to pop stack
    // increase pop stack size,
    // decrease size of stack and stackTop

    if (sz == 0 || stTop < 0)
    {
        return; // stack empty;
    }
    popSt[popSz] = st[sz - 1];
    popSz++;
    //st[sz - 1] = 0;
    sz--;
    stTop--;

    //  cout <<"\n\n  New sz : "<< sz << " New stTop : " << stTop<<endl<<endl;
    //  for (int i = 0; i < popSz; i++)
    //  {
    //       cout << "popSt[i] : " << popSt[i] << "  ";
    //   }
    //   cout << "\n\n New sz : " << sz << " New stTop : " << stTop << endl << endl;
}

void push(int *st, int &sz, int &stTop, int aNo)
{
    st[sz] = aNo;
   // cout<<" st[sz] : " <<st[sz];
    sz++;
    stTop++;
  //  cout <<" stTop : "<<stTop;
  //  display(st, sz);
}

bool foundInPopSt(int aNo, int *popSt, int &popSz)
{
    bool foundInPopSt = false;
    for (int i = 0; i < popSz; i++)
    {
        if (aNo == popSt[i])
        {
            foundInPopSt = true;
            // cout <<"\nFound in popSt"<<endl;
            break;
        }
    }
    return foundInPopSt;
}

int getTop(int *st, int stTop)
{
    int topEl = 0;
    topEl = st[stTop];
    return topEl;
}

void populateStack(int *st, int sz, int &stTop)
{
    int el;
    stTop = 0;
    cout << "\nEnter stack elements :\n";
    int cnt = 0;
    while (cnt < sz)
    {
        cin >> el;
        st[cnt] = el;
        stTop++;
        cnt++;
    }
}

void display(int *st, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        cout << st[i] << ", ";
    }
}
