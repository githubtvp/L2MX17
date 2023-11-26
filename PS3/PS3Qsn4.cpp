#include <iostream>
#include <string>
using namespace std;

const int MAXLEN = 150;
const string WHITESPACE = " ";
void pr(string str);
void prn();
typedef string prstr;

void getInputString(char *aStr, int &aLen);
void clearExtraWhiteSpaces(string &aStr, int aStPosn, int aEdPosn);
void findAndClearWhiteSpace(string &aStr);
void trimString(string &aStr);


int main()
{
    int theLen = MAXLEN;
    char theCStr[theLen];
    string theStr;
    getInputString(theCStr, theLen);    
    prn();
    theStr = string(theCStr); 
    pr(theStr);
    prn();
    trimString(theStr); 
  //  prn();
  //  pr(theStr);
    findAndClearWhiteSpace(theStr);
    pr("\nThe sentence after removel of blank spaces : \n\n");
    pr(theStr);
    prn();
    pr("\nPS3 Qsn4 Completed!");
}

void findAndClearWhiteSpace(string &aStr)
{
    int wsStPosn = 0;
    int wsEdPosn = 0;
    string findStr = WHITESPACE;  
    wsStPosn = aStr.find(findStr, wsStPosn);
    do
    {       
        wsEdPosn = aStr.find_first_not_of(findStr, wsStPosn);
        clearExtraWhiteSpaces(aStr, wsStPosn, wsEdPosn-1);
        wsStPosn+=1; 
        wsStPosn = aStr.find(findStr, wsStPosn);            
    } while (wsStPosn != string::npos);    
}


void clearExtraWhiteSpaces(string &aStr, int aStPosn, int aEdPosn)
{
    int theStPosn = aStPosn;
    int theEndPosn = aEdPosn;
    int theReplaceLen = theEndPosn - theStPosn + 1;
    aStr = aStr.replace(theStPosn, theReplaceLen, WHITESPACE);
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


void getInputString(char *aStr, int &aLen)
{
    int theLen = aLen;
    pr("\nEnter the sentence with some blank spaces(Max of 149 char) : \n");
    cin.getline(aStr, theLen);
    int i = 0;
    for (i = 0; aStr[i] != '\0'; i++)
    {
        // cout << aStr[i];
    }
    aLen = i;
}

void pr(string str)
{
    cout << str;
}

void prn()
{
    cout << endl;
}
