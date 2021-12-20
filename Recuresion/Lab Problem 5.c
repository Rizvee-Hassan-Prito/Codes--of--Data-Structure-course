#include<stdio.h>

int Bin(int n)
{
    if (n==0)return 0;
    return 10*Bin(n/2)+n%2;
}
int main()
{
    int x;
    scanf("%d",&x);
    int y=Bin(x);
    printf("%d",y);
}

