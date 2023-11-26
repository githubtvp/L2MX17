#include <iostream>
#include <string>
using namespace std;

const int MAXLEN = 100;
void pr(string str);
void prn();
typedef string prstr;

void getInputName(char *aName, int &aLen);
int getVowelCount(char aName[], int aLen);

int main()
{
    int nameLen = MAXLEN;
    char theName[nameLen]; // char theName[100] is C-string that will store
                           //  max 99 char or less and last 100th or
                           // last + 1 as '\0' to indicate end of c-string;
                           //  char *p = theName;
    getInputName(theName, nameLen);
    int theVowelCnt = getVowelCount(theName, nameLen);
    prstr str = "\nThe Vowel count : " + to_string(theVowelCnt);
    pr(str);
    pr("\n\nPS3 Qsn1 Completed!");
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
   // pr("\nLength of name : " + to_string(aLen));
}

int getVowelCount(char aName[], int aLen)
{
    int theLen = aLen;
    int theCnt = 0;
    for (int i = 0; i < theLen; i++)
    {
        if (aName[i] == 'a' || aName[i] == 'e' || aName[i] == 'i' || aName[i] == 'o' || aName[i] == 'u')
        {
            theCnt++;
        }
    }
    return theCnt;
}

void pr(string str)
{
    cout << str;
}

void prn()
{
    cout << endl;
}
