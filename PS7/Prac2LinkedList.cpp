#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(){};
    Node(int value) : data(value), next(nullptr) {}
};

void insertNodeAtBegining(int aData, Node *&aHead);
Node *getANewNode(int aData);
void printNodeData(Node *aHead);
Node *swapAdjacentNodes(Node *&aHead);

int main()
{
    Node *head = nullptr;
    Node *temp = nullptr;
    for (int i = 1; i < 10; i++)
    {
        int theData = 2 * i;
        insertNodeAtBegining(theData, temp);
    }
    head = temp;
    cout << "\n\nAfter insert at begining";
    printNodeData(head);
    swapAdjacentNodes(head);
    cout << "\n\nAfter swapAdjacent";
    printNodeData(head);

    //  cout << "\n---End Test line ---";
    return 0;
}

Node *swapAdjacentNodes(Node *&aHead)
{
    Node *temp;   //= new Node();
    Node *second; // = new Node();
    Node *third;  // = new Node();
    temp = aHead;
    aHead = aHead->next;
    // cout << "\n1. second->data : " ; //<< second->data;
   while (temp != nullptr && temp->next != nullptr)
    {
        Node *first = temp;
        Node *second = temp->next;
        Node *third = second->next;

        // Swap the nodes
        second->next = first;
    //    cout<<"\nfirst->data : " <<first->data;
        first->next = (third != nullptr && third->next != nullptr) ? third->next : third;
    //    cout<<"\nfirst-next->data : " <<first->next->data;
     //   cout<<"first->data : " <<first->data;

       // first->next = (third != nullptr && third->next != nullptr) ? third : third->next;

        // Update temp for the next iteration
        temp = third;
    }

    return aHead;
}

Node *getANewNode(int aData)
{
    return (new Node(aData));
}

void insertNodeAtBegining(int aData, Node *&aHead)
{
    if (aHead == NULL) ///*NULL*/
    {
        aHead = getANewNode(aData);
        //  cout <<"\nA. aHead Data : "<<aHead->data<<endl;
    }
    else
    {
        // cout <<"\nB. aHead Data : "; //<<aHead->data<<endl;
        Node *newNode = new Node(aData);
        newNode->next = aHead;
        aHead = newNode;
    }
    //  cout <<"\nB. aHead Data : "<<aHead->data<<endl;
}

void printNodeData(Node *aHead)
{
    Node *temp = aHead;
    while (temp != nullptr)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
}
