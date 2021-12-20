#include<stdio.h>

int Count(int n)
{
    if (n==0)return 0;
    return 1+Count(n/10);
}
int main()
{
    int x;
    scanf("%d",&x);
    int y=Count(x);
    printf("%d",y);
}

