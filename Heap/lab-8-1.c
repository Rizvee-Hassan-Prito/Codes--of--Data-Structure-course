#include<stdio.h>
void Max_Heap(int a[],int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
    {
        Heapify(a,n,i);
    }
}
int Heapify(int a[],int n,int i)
{
   int l,r,lrgst;
   l=2*i+1;
   r=2*i+2;
   if(l<=n && a[l]>a[i])
   {
       lrgst=l;
   }
   else{
        lrgst=i;
       }
   if(r<=n && a[r]>a[lrgst])
   {
       lrgst=r;
   }
   if(lrgst!=i)
   {
       int k=a[lrgst];
       a[lrgst]=a[i];
       a[i]=k;
       Heapify(a,n,lrgst);
   }
   return 0;
}
void lrgstElmts(int a[],int n,int k)
{
    int i;
    for(i=k;i>0;i--)
    {
        printf("\nLarge element :%d\n",a[0]);
        a[0]=a[n-1];
        n--;
        Max_Heap(a,n);
    }
}
int main()
{
    int n,i,a[100],k;
    printf("\nEnter number of elements:\n");
    scanf("%d",&n);
    printf("\nEnter elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    Max_Heap(a,n);
    printf("\nMax Heap:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nEnter the largest elements number:\n");
    scanf("%d",&k);
    lrgstElmts(a,n,k);
}
