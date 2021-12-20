#include <stdio.h>
#include <string.h>
void rev(char str[],int x)
{
    char c;
    if(strlen(str)-x==strlen(str)-(strlen(str)-x)-1)return;
    c=str[strlen(str)-x];
    str[strlen(str)-x]=str[strlen(str)-(strlen(str)-x)-1];
    str[strlen(str)-(strlen(str)-x)-1]=c;
    rev(str,x-1);
}
int main()
{
    char str[100];
    scanf("%s",str);
    rev(str,strlen(str));
    printf("%s",str);
}
