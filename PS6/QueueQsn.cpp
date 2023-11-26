#include <iostream>
#include <string>

using namespace std;

void push(int qSz, int *stQ, int &sz, int &rear, int &front, int item);
void pop(int qSz, int *stQ, int &sz, int &front);

void pr(int *stQ, int front, int rear);
int main()
{
    int qSz = 5;
    int *stQ = new int[qSz];
    int front = -1;// front of queue
    int rear = -1;//rear of queue
    int sz = 0;
    int item = 10;
    push(qSz, stQ, sz, rear, front, item);
    item = 20;
    push(qSz, stQ, sz, rear, front, item);
    item = 30;
    push(qSz, stQ, sz, rear, front, item);
    pr(stQ, front, rear);
    cout << "\n\nPop opns\n";
    pop(qSz, stQ, sz, front);
    pr(stQ, front, rear);
    pop(qSz, stQ, sz, front);
    pr(stQ, front, rear);
    cout<<"\nLast pop\n";
    pop(qSz, stQ, sz, front);
    pr(stQ, front, rear);
    
    cout << "\nTest line Stack Qsn 1";
    return 0;
}

void pop(int qSz, int *stQ, int &sz, int &front)
{
    int itemPopped = 0;
    if (sz <= 0)
    {
        cout << "\n Stack Empty ";
    }
    else
    {
        itemPopped = stQ[front];
        sz--;
        front++;
        cout << "\n Item popped : " << itemPopped;
    }
}

void push(int qSz, int *stQ, int &sz, int &rear, int &front, int item)
{
    if (sz == qSz)
    {
        cout << "\nStack overflow";
    }
    else
    {
        //     cout << "\nPush item : " << item;
        stQ[++rear] = item;
        sz++;  
        if(sz==1)
        {
            front++;
        }                
        // cout <<"\nItem in array : "<< stQ[sz-1];
    }
}

void pr(int *stQ, int front, int rear)
{
    if(front > rear ) 
    {
        cout <<"\nQueue empty!";
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        cout << "\n " << *(stQ + i);
    }
}
