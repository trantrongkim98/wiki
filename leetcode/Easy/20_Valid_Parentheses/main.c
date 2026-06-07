#include "string.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#define false 0
#define true 1 // Option 1
#define true !false // Option 2
bool isValid(char *s)
{
    int strLen = strlen(s);
    char *temp = malloc(strLen);
    int tempIndex = 0;
    if (strLen == 0)
        return true;
    if (strLen % 2 == 1)
        return false;
    int i = 0;
    while(s[i]!='\0'){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            temp[tempIndex] = s[i];
            tempIndex+=1;
        } else if(tempIndex>0 && (s[i]-temp[tempIndex-1]==1 || s[i]-temp[tempIndex-1] == 2)){
           tempIndex--;
        } else return false;
        i++;
    }
    

    return tempIndex <1;
}

int main()
{

    printf("%d\n",  isValid("(){}{}"));
    return 0;
}