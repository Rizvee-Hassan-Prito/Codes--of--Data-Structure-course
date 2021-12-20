#include<stdio.h>
void Max_Heap(int a[],int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
    {
        Max_Heapify(a,n,i);
    }
}
void Min_Heap(int a[],int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
    {
        Min_Heapify(a,n,i);
    }
}
int Max_Heapify(int a[],int n,int i)
{
   int l,r,lrgst;
   l=2*i+1;
   r=2*i+2;
   if(l<n && a[l]>a[i])
   {
       lrgst=l;
   }
   else{
        lrgst=i;
       }
   if(r<n && a[r]>a[lrgst])
   {
       lrgst=r;
   }
   if(lrgst!=i)
   {
       int k=a[lrgst];
       a[lrgst]=a[i];
       a[i]=k;
       Max_Heapify(a,n,lrgst);
   }
   return 0;
}
int Min_Heapify(int a[],int n,int i)
{
   int l,r,lrgst;
   l=2*i+1;
   r=2*i+2;
   if(l<n && a[l]<a[i])
   {
       lrgst=l;
   }
   else{
        lrgst=i;
       }
   if(r<n && a[r]<a[lrgst])
   {
       lrgst=r;
   }
   if(lrgst!=i)
   {
       int k=a[lrgst];
       a[lrgst]=a[i];
       a[i]=k;
       Min_Heapify(a,n,lrgst);
   }
   return 0;
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
    printf("\nMax :%d",a[0]);
    Min_Heap(a,n);
    printf("\nMin :%d",a[0]);
}
