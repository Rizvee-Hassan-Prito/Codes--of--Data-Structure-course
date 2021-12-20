#include<stdio.h>
void Min_Heap(int a[],int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
    {
        Heapify(a,n,i);
    }
}
int Heapify(int a[],int n,int i)
{
   int l,r,smlst;
   l=2*i+1;
   r=2*i+2;
   if(l<n && a[l]<a[i])
   {
       smlst=l;
   }
   else{
        smlst=i;
       }
   if(r<n && a[r]<a[smlst])
   {
       smlst=r;
   }
   if(smlst!=i)
   {
       int k=a[smlst];
       a[smlst]=a[i];
       a[i]=k;
       Heapify(a,n,smlst);
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
    Min_Heap(a,n);
    printf("\nMin Heap:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}


