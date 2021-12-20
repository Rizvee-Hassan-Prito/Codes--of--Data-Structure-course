#include<stdio.h>

int GCD(int a,int b)
{
    if(b==0){return a;}
    return GCD(b,a%b);
}
int main()
{
    int x,n;
    scanf("%d",&x);
    scanf("%d",&n);
    int y=GCD(x,n);
    printf("%d",y);

}
