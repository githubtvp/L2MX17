#include <iostream>
#include <string>
using namespace std;

const int MAXLEN = 100;
void pr(string str);
void prn();
typedef string prstr;

void getInputName(char *aName, int &aLen);
void printNameReverse(char aName[], int aLen);
void makeACopy(char *aName, int &aLen,char *aNameCpy, int &aLenCpy);

int main()
{
    int nameLen = MAXLEN;
    char theName[nameLen]; // char theName[100] is C-string that will store
                           //  max 99 char or less and last 100th or
                           // last + 1 as '\0' to indicate end of c-string;
                           //  char *p = theName;
    getInputName(theName, nameLen);  
    prn();
    printNameReverse(theName, nameLen);
    int nameLenCpy = nameLen;
    char theNameCpy[nameLenCpy];
    makeACopy(theName, nameLen, theNameCpy, nameLenCpy);
    prn();
    pr("\n Your copied name : ");
    for (int i = 0; i < nameLenCpy; i++)
    {
       cout << theNameCpy[i];
    }    
//  int theVowelCnt = getVowelCount(theName, nameLen);
  //  prstr str = "\nThe Vowel count : " + to_string(theVowelCnt);
 //  pr(str);
    pr("\n\nPS3 Qsn2 Completed!");
}

void makeACopy(char *aName, int &aLen,char *aNameCpy, int &aLenCpy)
{
    int theLen = aLen;
    int i = 0;
    //cin.getline(aName, theLen);
    do
    {
        aNameCpy[i] = aName[i];
        i++;
    } while (aName[i] != '\0');
    aLenCpy = i;           
}

void getInputName(char *aName, int &aLen)
{
    int theLen = aLen;
    int i = 0;
    pr("\nEnter your name :  ");
    cin.getline(aName, theLen);
    do
    {
        i++;
    } while (aName[i] != '\0');
    aLen = i;
    pr("\nLength of your name : " + to_string(aLen));
}

void printNameReverse(char aName[], int aLen)
{
    int theLen = aLen;
    pr("\nYour name in reverse :  ");
     for (int i = theLen-1; i >=0; i--)
    {
       cout << (aName[i]);
    }
  //  return theCnt;
}

void pr(string str)
{
    cout << str;
}

void prn()
{
    cout << endl;
}
