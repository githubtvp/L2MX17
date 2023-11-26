#include <iostream>
#include <string>
using namespace std;

const string WHITESPACE = " ";
void pr(string str);
void prn();
typedef string prstr;

void getInputString(string &str1);
void processStrings(string &str1);
void trimString(string &aStr);

int main()
{
    string theStr;
    getInputString(theStr);
    trimString(theStr);
  //  theStr = "bBAadefAaghBbjkACacretAaBbBbwqBBbbhACacACBACacbBac";
    prn();
    pr(theStr);
    processStrings(theStr);
    prn();
    pr(theStr);
    prn();
    pr("\nPS4 Qsn4 Completed!");
}

void getInputString(string &str)
{
    pr("\nEnter string 1 : ");
    cin >> str;
}

void trimString(string &aStr)
{
    int wsStPosn = 0;
    int wsEdPosn = 0;
    string findStr = WHITESPACE;
    wsEdPosn = aStr.find_first_not_of(findStr);
    prn();
    if (wsEdPosn != string::npos)
    {
        aStr = aStr.substr(wsEdPosn);
    }
    wsEdPosn = aStr.find_last_not_of(findStr);
    if (wsEdPosn != string::npos)
    {
        aStr = aStr.substr(0, wsEdPosn + 1);
    }
}

void processStrings(string &str)
{
    int theLen = str.size();
    if (theLen == 0)
    {
        return;
    }
    else
    {
        for (int i = 0; i < theLen; i++)
        {
            if ('b' == str[i])
            {
                str.replace(i,1,"");
                i--;
            }
            else if (i < theLen - 1 && 'a' == str[i] && 'c' == str[i+1])
            {             
               str.replace(i,1,"");
               str.replace(i,1,"");
               i--;
            }
        }
    } 
}

void pr(string str)
{
    cout << str;
}

void prn()
{
    cout << endl;
}
