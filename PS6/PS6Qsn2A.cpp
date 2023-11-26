#include <iostream>
#include <string>

using namespace std;

const int MAX = 15;

struct arrSt
{
    int *mainSt;
    int *maxSt;
    int stTop = -1;
    int sz = 0;
    int mTop = -1;
    int mSz = 0;
} st;

class theStack
{
private:
    int arr[MAX];
    int top;
    int sz;
    /* data */
public:
    theStack()
    {
        arr[MAX] = {0};
        top = -1;
        sz = 0;
    };
    ~theStack()
    {

    };
    void push(int aNo)
    {
        if(sz < MAX)
        {
            arr[sz++] = aNo;
            top++;
        }
        else{
            cout << "\nStack full!";
        }
    };

    bool isNotEmpty()
    {
        return sz;
    }

    int pop()
    {
        int el;
        if(isNotEmpty())
        {
            el = arr[top--];
            sz--;
        };
        return el;
    };
    int getTop()
    {
        return arr[top];
    }
    int getSz()
    {
        return sz;
    }
};



void push(int aNo);
void prMainSt();
void prMaxSt();
void getMax();

int main()
{
    int sz = 0, mSz = 0;
    sz = mSz = 5;
    st.mainSt = new int[sz];
    st.maxSt = new int[mSz];
    push(5);
    push(6);
    push(4);
    push(7);
    push(3);
    push(2);
    prMainSt();
    cout << endl << endl;
    prMaxSt();
    getMax();
    cout << "\n\nTest line PS6Qsn2";

    theStack mySt;
    mySt.push(9);
    cout <<"\nGet top mySt : "<< mySt.getTop();
    cout <<"\nPop el : "<< mySt.pop();
    return 0;
}

void getMax()
{
    cout << "\nMax value  in stack : " << st.maxSt[st.mTop] << " ";
}

void push(int aNo)
{
    st.mainSt[st.sz] = aNo;
    st.sz++;
    st.stTop++;
    if ((st.mTop < 0) || (aNo > st.maxSt[st.mTop]))
    {
        st.maxSt[st.mSz] = aNo;
        st.mSz++;
        st.mTop++;
    }
}

void prMainSt()
{
    for (int i = 0; i < st.sz; i++)
    {
        cout << " " << st.mainSt[i] << " ";
    }
}

void prMaxSt()
{
    for (int i = 0; i < st.mSz; i++)
    {
        cout << " " << st.maxSt[i] << " ";
    }
}
