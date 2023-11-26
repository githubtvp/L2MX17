#include<iostream>
#include<string>

using namespace std;

const int MAX = 15;
struct stk
{
    int *arr = new int[MAX];
    int top = -1;
    int sz = 0;
};

stk st = new stk();
int main()
{
    string str;
    cout <<"\nEnter the input Postfix expression : \n";
    cin>> str;
    cout<<"\nYou entered :\n "<<str;
    //cout<<"\nTest line Qsn 4";
    return 0;
}

void processString(string str)
{
    for(int i =0; i < str.length(); i++)
    {
         if( isdigit(str[i]))
        {

        }
    }
}

void push(int aNo)
{
    st.arr[sz++] = aNo;
    st.top++;
}

int pop()
{
    int theNo = st.arr[top--];
    sz--;
    return theNo;
}
