#include <iostream>
#include <string>
using namespace std;

const string WHITESPACE = " ";
void pr(string str);
void prn();
typedef string prstr;

void getInputString(string &str1, string &str2);
void processStrings(string str1, string str2);
void trimString(string &aStr);

int main()
{
    string theStr1, theStr2;
    getInputString(theStr1, theStr2);
    trimString(theStr1);
    trimString(theStr2);
    processStrings(theStr1, theStr2);
    prn();
    pr("\nPS4 Qsn3 Completed!"); 
}

void getInputString(string &str1, string &str2)
{
    pr("\nEnter string 1 : ");
    cin >> str1;
    pr("\nEnter string 2 : ");
    cin >> str2;
}

void trimString(string &aStr)
{
     int wsStPosn = 0;
    int wsEdPosn = 0;
    string findStr = WHITESPACE;
    wsEdPosn = aStr.find_first_not_of(findStr);
    prn();
    if(wsEdPosn != string::npos)
    {
        aStr = aStr.substr(wsEdPosn);
       // pr(aStr);
    }
    wsEdPosn = aStr.find_last_not_of(findStr);
    if(wsEdPosn != string::npos)
    {
        aStr = aStr.substr(0, wsEdPosn + 1);
    }
}

void processStrings(string str1, string str2)
{
    bool found = true;
    int theLen1 = str1.size();
    int theLen2 = str2.size();
    if (theLen1 != theLen2)
    {
        pr("Lengths are not same, Not Anagrams!");
        return;
    }
    else
    {
        for (int i = 0; i < theLen1 && found; i++)
        {
            for (int j = 0; j < theLen2 && found; j++)
            {
                if (str1[i] == str2[j])
                {
                    break;
                }
                else if (j == (theLen2 - 1))
                {
                    pr("The two strings are Not Anagram!");
                    found = false;
                }
            }
        }
        if (found)
        {
            pr("The two strings are Anagram!");
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
