#include <iostream>
#include<iomanip>
#include <string>

using namespace std;
void pr(string str);
void prn();
typedef string prstr;


int main()
{
    int noOfPens;
    printf("\nEnter number of pens to place in stand : ");
    scanf("%d", &noOfPens);
   // printf("\nYou entered : %d", noOfPens);
    if(noOfPens > 5)
          printf("\nPen stand full! ");
    printf("\nCompleted\n");
    return 0;
}
