#include<stdio.h>

int Rev(int n)
{
    static int r=0;
    if(n==0)return n;
    r=r*10+n%10;
    Rev(n/10);
    return r;
}
int main()
{
    int x;
    scanf("%d",&x);
    int y=Rev(x);
    if(y==x)printf("Palindrome.");
    else printf("Not Palindrome.");
}


