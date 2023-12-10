#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(){};
    Node(int d) : data(d), next(nullptr){};
};

int arr[] = {2, 3, 5, 7, 9};
void prN(Node *aHead, int sz);
void insertNode(Node *&head, Node *&tail, int data);
void insertNodeAt(Node *&head, Node *&tail, int data);
int main()
{
    int sz = 5;
    Node *head = nullptr;
    Node *tail = nullptr;
    for (int i = 0; i < sz; i++)
    {
        insertNode(head, tail, arr[i]);
    }
    prN(head, sz);
    int data = 1;
    cout << endl;
    insertNodeAt(head, tail, data);
    prN(head, sz + 1);
    cout << "\nTest line " << endl;
    return 0;
}

void insertNodeAt(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;
    if (data <= head->data)
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
        return;
    }
    while (temp->next->data < data && temp != tail)
    {
        temp = temp->next;
    }
    if (temp == tail)
    {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertNode(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        tail->next = head;
    }
    else
    {
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
}

void prN(Node *aHead, int sz)
{
    if (aHead == nullptr)
    {
        return;
    }
    else
    {
        Node *temp = aHead;
        int cnt = 0;
        while (cnt < sz)
        {
            cout << temp->data;
            temp = temp->next;
            cnt++;
            if (cnt < sz)
                cout << "->";
        }
    }
}