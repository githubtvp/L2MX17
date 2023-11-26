#include <iostream>
#include <string>
using namespace std;

const int MAXLEN = 100;
void pr(string str);
void prn();
typedef string prstr;

void getInputName(char *aName, int &aLen);
void convertToUpper(char *aName, int &aLen);

int main()
{
    int theLen = MAXLEN;
    char theName[theLen];
    getInputName(theName, theLen);
    convertToUpper(theName, theLen);
    pr("\nYour name is : ");
    int i =0;
    do
    {
        cout << theName[i];
        i++;
    }while (theName[i] != '\0');
    prn();
    pr("The number of ch is : " + to_string(theLen));
    prn();
    pr("\nPS3 Qsn3 Completed!");
}

void getInputName(char *aName, int &aLen)
{
    int theLen = aLen;
    pr("\nEnter your name : ");
    cin.getline(aName, theLen);
    int i =0;
    do
    {
       i++;
    }while(aName[i]!= '\0');
   // pr("The number of ch is : " + to_string(i));
    aLen = i;
}

void convertToUpper(char *aName, int &aLen)
{
    int theLen = aLen;
    int i =0;
    char aCh;
    do
    {
        aCh = aName[i];
        if(aCh != ' ')
        aName[i] = toupper(aCh);
       i++;
    }while(aName[i]!= '\0');
    pr("The number of ch is : " + to_string(i));

}

void pr(string str)
{
    cout << str;
}

void prn()
{
    cout << endl;
}
