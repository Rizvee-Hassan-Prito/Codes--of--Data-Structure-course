#include<stdio.h>
int MaxNum(int a[],int n,int y,int max)
{
 if(y==n){return max;}
 if(max<a[y])
    {
        max=a[y];
    }
    return MaxNum(a,n,y+1,max);
}
int main()
{
    while(1){
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int y=MaxNum(a,n,0,0);
    printf("Max element: %d",y);
    }
}
