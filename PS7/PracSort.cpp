#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(){};
    Node(int aNo) : data(aNo), next(nullptr){};
};

void bubbleSortArr(int *a, int sz);
void selectionSortArr(int *a, int sz);
void insertionSortArr(int *a, int sz);
int binarySearch(int *a, int sz, int x);
void pr(int *a, int sz);
int main()
{
    int b[8] = {4, 5, 2, 3, 1, 7, 9, 0};
    int sz = 8;
    int *a;
    a = b;
    // int sz;
    //  cout <<"\nEnter size sz : ";
    // cin >> sz;
    //  a = new int[sz];
    // cout <<"\nEnter Elements : ";
    // for(int i = 0; i < sz; i++)
    // {
    //     cin >> a[i];
    // }
    pr(a, sz);
    cout << "\nSortingsteps : " << endl;
    // bubbleSortArr(a, sz);

    //   cout << "\nSelection Sort : " << endl;
    //  selectionSortArr(a, sz);

    cout << "\nInsertion Sort : " << endl;
    insertionSortArr(a, sz);

    cout << "\nBinary Search : " << endl;
    int elAtIndx, x;
    x = 5;
    elAtIndx = binarySearch(a,sz, x);
    cout << "\nElement found at index : "<<elAtIndx;
    cout << "\nTest line ";
    return 0;
}

int binarySearch(int *a, int sz, int x)
{
    int left = 0, right = sz - 1, mid;
    bool found = false;
    while (left <= right && !found)
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
        {
            found = true;
           // cout<<"\nEl found!";
        }
        if (a[mid] < x)
        {
            // cout<<"\n2. Here \n";
            left = mid + 1;
        }
        else
        {
           //  cout<<"\n3. Here \n";
            right = mid- 1;
        }
    }
    if (found)
    {
        return mid;
    }
    else
    {
        return -1;
    }
}

void insertionSortArr(int *a, int sz)
{
    int firstOutOfOrder = 1;
    int loc, temp;
    for (firstOutOfOrder = 1; firstOutOfOrder < sz; firstOutOfOrder++)
    {
        if (a[firstOutOfOrder] < a[firstOutOfOrder - 1])
        {
            loc = firstOutOfOrder;
            temp = a[loc];
            do
            {
                a[loc] = a[loc - 1];
                loc--;
            } while (loc > 0 && a[loc - 1] > temp);
            a[loc] = temp;
        }
        pr(a, sz);
        cout << endl;
    }
}

void selectionSortArr(int *a, int sz)
{
    int i, j, minIndx;
    for (i = 0; i < sz - 1; i++)
    {
        minIndx = i;
        for (j = i + 1; j < sz; j++)
        {
            if (a[minIndx] > a[j])
            { // swap
                minIndx = j;
            }
        }
        if (i != minIndx)
        {
            int temp = a[minIndx];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
        pr(a, sz);
        cout << endl;
        // cout << endl;
    }
}

void bubbleSortArr(int *a, int sz)
{
    int i, j;
    for (i = 1; i < sz; i++)
    {
        for (j = 0; j < sz - i; j++)
        {
            if (a[j] > a[j + 1])
            { // swap
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            pr(a, sz);
            cout << endl;
        }
        cout << endl;
    }
}

void pr(int *a, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        cout << a[i] << " ";
    }
}