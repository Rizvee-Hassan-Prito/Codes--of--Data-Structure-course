#include<stdio.h>

void print(int n)
{
    if(n==0)return;
    printf("%d\n",n);//for a
    print(n-1);
    //printf("%d\n",n); //for b

}
int main()
{
    int x;
    scanf("%d",&x);
    print(x);
}
