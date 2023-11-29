#include <iostream>
#include <string>
#include <time.h>

using namespace std;

const int SZ = 100;
const int MAXNO = 100;

struct myStack
{
    int maxSz = SZ;
    int arr[SZ];
    int sz = 0;
    int top = -1;
    int stMax = 0;
    int stMin = MAXNO + 1;
    bool empty = true;
};

struct myQueue
{
    int maxSz = SZ;
    int arr[SZ];
    int sz = 0;
    int front = -1;
    int rear = -1;
    bool empty = true;
};

struct myStack st;
struct myQueue que;

void tfrToSt(int arr[], int sz);
void populateStk(int sz);
void pushSt(int aNo);
void emptyStk(int sz);
void popSt();
void prSt();
int getStTop();

void populateQue(int sz);
void pushQ(int aNo);
void emptyQ(int sz);
void popQ();
void prQ();
int getQFront();
void stackToQue(int A[], int &minPosn, int &maxPosn);
void queToStack();
void prA(int A[], int sz);
int main()
{
    srand(0);
    int sz = 5;
    // populateStk(sz);
    int A[5] = {26, 93, 77, 44, 20};
  //  prA(A, sz);
    tfrToSt(A, sz);
    //  cout <<"After tfr"<<endl;
    //  prSt();
    int minPosn, maxPosn;
    minPosn = 0;
    maxPosn = sz - 1;   
    while (minPosn <= maxPosn)
    {
        stackToQue(A, minPosn, maxPosn);        
        queToStack(); 
    }
    // cout << "\nAfter st to que" << endl;
    // prSt();
    // prQ();
    prA(A, sz);
    // emptyStk(sz);
    // cout <<"\nQueue opns :\n"<<endl;
    // populateQue(sz);
    //  emptyQ(sz);
    //  cout <<"Test line";
    return 0;
}

void queToStack()
{    
    while (!que.empty)
    {
        pushSt(getQFront());
        popQ();       
    }
    prSt();
}
void stackToQue(int A[], int &minPosn, int &maxPosn)
{
    for (int i = 0; !(st.empty); i++)
    {
        int topEl = getStTop();
      //  cout <<"\n2. Top El : "<<topEl;;
        if ((topEl > st.stMin) && (topEl < st.stMax))
        {
            pushQ(topEl);
          //  cout <<"\nPush Q : "<< topEl << " " <<st.stMin;
        }
        else if (topEl == st.stMax)
        {
            A[maxPosn--] = topEl;
           // cout << "\nA[maxPosn -1] : " << topEl << st.stMax;
        }
        else if (topEl == st.stMin)
        {
            A[minPosn++] = topEl;
           // cout << "\nAAA[minPosn+1] : " << topEl;
        }
        popSt();
    }
    prQ();
}

void populateQue(int sz)
{
    int i = sz;
    while (i > 0)
    {
        int aNo = rand() % MAXNO + 1;
        pushQ(aNo);
        i--;
    }
    prQ();
}

void pushQ(int aNo)
{
    if (que.sz == que.maxSz)
    {
        cout << "\nQueue full! " << endl;
    }
    else
    {
        if (0 == que.sz)
        {
            que.front++;
            que.empty = true;
        }
        que.arr[que.sz++] = aNo;
        que.rear++;
        que.empty = false;
    }
}

void emptyQ(int sz)
{
    int i = sz;
    while (i > 0)
    {
        popQ();
        i--;
    }
    que.empty = true;   
}

void popQ()
{
    if (0 == que.sz)
    {
        cout << "\nQue empty" << endl;
    }
    else
    {
        // cout << "\nQue : Popped element : " << que.arr[que.front];
        que.sz--;
        que.front++;
        if (0 == que.sz)
        {
            que.empty = true;
            que.front = -1;
            que.rear = -1;
        }
    }
}

void tfrToSt(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        pushSt(arr[i]);
    }
    prSt();
}

void populateStk(int sz)
{
    int i = sz;
    while (i > 0)
    {
        int aNo = rand() % MAXNO + 1;
        pushSt(aNo);
        i--;
    }
}

void emptyStk(int sz)
{
    int i = sz;
    while (i > 0)
    {
        popSt();
        i--;
    }    
}

void pushSt(int aNo)
{
    if (st.sz == st.maxSz)
    {
        cout << "\nStack full!" << endl;
    }
    else
    {
        st.arr[st.sz++] = aNo;
        st.top++;
        st.empty = false;
        if (st.stMax < aNo)
        {
            st.stMax = aNo;
            // cout <<"\nStack : stMax : "<<st.stMax;
        }
        if (st.stMin > aNo)
        {
            st.stMin = aNo;
            // cout <<"\nStack : stMin : "<<st.stMin;
        }
    }
}

void popSt()
{
    if (0 == st.sz)
    {
        cout << "\nStack empty" << endl;
        st.empty = true;
    }
    else
    {
        //  cout << "\nStack : Popped element : " << st.arr[st.top];
        st.sz--;
        st.top--;
        if (0 == st.sz)
        {
            st.top = -1;
            st.empty = true;
            st.stMax = 0;
            st.stMin = MAXNO + 1;
        }
    }
}

int getStTop()
{
    if (-1 == st.top)
    {
        cout << "\nStack empty" << endl;
        return 0;
    }
    return st.arr[st.top];
}

int getQFront()
{
    if (-1 == que.front)
    {
        cout << "\nQueue empty" << endl;
        return 0;
    }
    return que.arr[que.front];
}

void prSt()
{
    cout << "\nStack :  ";
    for (int i = 0; i < st.sz; i++)
    {
        cout << st.arr[i] << "  ";
    }
}

void prQ()
{
    cout << "\nQueue :  ";
    for (int i = que.front; i <= que.rear; i++)
    {
        cout << que.arr[i] << "  ";
    }
}

void prA(int A[], int sz)
{
    cout << "\nArray :  ";
    for (int i = 0; i < sz; i++)
    {
        cout << A[i] << "  ";
    }
}
