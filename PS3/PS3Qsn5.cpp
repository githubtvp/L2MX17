#include <iostream>
#include <string>
using namespace std;

const int MAXLEN = 150;
const string WHITESPACE = " ";
void pr(string str);
void prn();
typedef string prstr;

void getInputString(char *aStr, int &aLen, int &aWdth);
void trimString(string &aStr);;
void segmentTheSentence(string &aStr, int aWdth);

int main()
{
    int theLen = MAXLEN, theWidth = 0;
    char theCStr[theLen];
    string theStr;
    getInputString(theCStr, theLen, theWidth);    
    prn();
    theStr = string(theCStr); 
    trimString(theStr);
    segmentTheSentence(theStr, theWidth); 
    prn();
    pr("\nPS3 Qsn4 Completed!");
}


void getInputString(char *aStr, int &aLen, int &aWdth)
{
    int theLen = aLen;
    int theWidth = aWdth;
    pr("\nEnter a sentence (Max of 149 char) : ");
    cin.getline(aStr, theLen);
    pr("\nEnter the width of segments to break the sentence into : ");
    cin >> theWidth;
    int i = 0;
    for (i = 0; aStr[i] != '\0'; i++)
    {
        // cout << aStr[i];
    }
    aLen = i;
    aWdth = theWidth;
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

void segmentTheSentence(string &aStr, int aWdth)
{
    int theStPosn = 0;
    int theWidth = aWdth;
    string segStr = " ";  
    do
    {       
        segStr = aStr.substr(theStPosn, theWidth);
        pr(segStr);
        prn();
        theStPosn +=theWidth;    
    } while (theStPosn <= aStr.size());   
}

void pr(string str)
{
    cout << str;
}

void prn()
{
    cout << endl;
}
