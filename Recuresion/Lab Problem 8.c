#include <stdio.h>
#include <string.h>
int count(char str[],int x)
{
    if(str[x]==NULL){return;}
    return 1+count(str,x+1);
}
int main()
{
    char str[100],qtr[100];
    gets(str);
    printf("%d",count(str,0));
}

