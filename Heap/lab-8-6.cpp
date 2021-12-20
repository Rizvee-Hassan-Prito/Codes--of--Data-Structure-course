#include<stdio.h>
#include<iostream>
using namespace std;
class Priority_Queue
{
    int heap[50];
    int length=-1;
public:
    void insert (int x)
    {
        length = length + 1;
        heap[length] = -99999;
        increase_key(length,x);
    }
    int maximum()
    {
        return heap[0];
    }
    int extract_max()
    {
    if(length == 0)
    {
        cout<<"heap overflow.";
        return -1;
    }
    int max = heap[0];
    heap[0] = heap[length];
    length = length -1;
    Max_Heapify(heap,length,0);
    return max;
    }
int increase_key(int i,int val)
    {
        if(val<heap[i])
        {
          return -1;
        }
        heap[i]=val;
        while(i>0 && heap[i/2]<heap[i])
        {
            int f=heap[i/2];
            heap[i/2]=heap[i];
            heap[i]=f;
            i=i/2;
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
 void Print()
 {
   for(int i=0;i<=length;i++)
    {
        cout<<heap[i]<<endl;
    }
 }
};
int main()
{
    Priority_Queue PQ;
    PQ.insert(3);
    PQ.insert(5);
    PQ.insert(9);
    PQ.insert(6);
    PQ.insert(8);
    PQ.insert(20);
    PQ.insert(10);
    PQ.insert(12);
    PQ.insert(18);

    //cout<<PQ.extract_max()<<endl;
    PQ.Print();

}
