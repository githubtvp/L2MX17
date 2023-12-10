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
        }
        if (a[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
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
        //first point when its not sorted
        if (a[firstOutOfOrder] < a[firstOutOfOrder - 1])
        {//store the indx in loc var and value in temp
            loc = firstOutOfOrder;
            temp = a[loc];
            do
            {//loc starts moving left in every iteration
            //and continues the iteration until the elements are > temp
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
        minIndx = i;//
        for (j = i + 1; j < sz; j++)
        {
            if (a[minIndx] > a[j])
            { // swap
                minIndx = j;//store the new lower index  
            }
        }
        if (i != minIndx)
        {//swap when min Indx has been changed
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
    for (i = 1; i < sz; i++)//start from 1 so that can compare 0 index in next loop
    {
        for (j = 0; j < sz - i; j++)//NOTE : sz - I
        {//from 0 to sz - I 
            if (a[j] > a[j + 1])
            { // swap elements when needed 
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