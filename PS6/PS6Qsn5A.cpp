#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int> &s, int item)
{
    if (s.empty())
    {
        s.push(item);
    }
    else
    {
        // Recursively move items to the bottom
        int temp = s.top();
        s.pop();
        insertAtBottom(s, item);
        s.push(temp);
    }
}

// Function to sort a stack using recursion
void sortStack(stack<int> &s)
{
    if (!s.empty())
    {
        // Pop the top element
        int temp = s.top();
        s.pop();

        // Sort the remaining stack
        sortStack(s);

        // Insert the popped element in the sorted stack
        insertAtBottom(s, temp);
    }
}

int main()
{
    stack<int> s;

    // Push some elements onto the stack
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    cout << "\nOriginal Stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    sortStack(s);

    cout << "\nReversed Stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
