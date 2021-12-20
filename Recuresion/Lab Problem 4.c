#include<stdio.h>

int fibonacci(int n)
{
    if (n<=1)return n;
    printf("%d\n",n);
    return fibonacci(n-1) + fibonacci(n-2);
}
int main()
{
    int x;
    scanf("%d",&x);
    int y=fibonacci(x);
    printf("%d",y);
}

