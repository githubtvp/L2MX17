#include <iostream>
#include <string>
#include<time.h>

using namespace std;

const int MAXNO = 10;
struct Node
{
    int data = 123;
    Node *next = NULL;
    Node *prev = NULL;
};
Node *n = new Node();

void push(int d);
void buildLinkedList(int aSz);
void printList();

int main()
{
    srand(time(0));  
    int sz = 5;
    buildLinkedList(sz);  
    cout<<"\nPrint list : \n";
    printList();
    return 0;
}

void buildLinkedList(int aSz)
{
    for(int i=0; i <aSz; i++)
    {
        int aData = rand()%MAXNO + 1;
        cout <<"\n Data : "<<aData;
        push(aData);
    }
    
}
void push(int d)
{
    Node *temp = n;
    Node *newN = new Node();
    if( n == NULL ) // no list exists 
    {
        n->data = d;
       // n = newN;
        n->prev = NULL;
        n->next->data = 9;
        return;
    }
    else if(temp->prev == NULL)
    {
         newN->data = d;
         newN->next = n;
         n->prev = newN;
         n = newN;
    }
}

void printList()
{
    Node *temp = n;
   //cout<<endl;
    while(temp != NULL)
    {
        cout<<"  1.  "<<temp->data;
        temp=temp->next;
    }
}