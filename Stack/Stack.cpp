#include<iostream>
#include<stdio.h>
#define STACK_MAX_SIZE 50
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define TRUE_VALUE 1
#define FALSE_VALUE 0

class Stack
{
private:
    int data[STACK_MAX_SIZE];
    int top;
public:
    Stack()
    {
        top=0;
    }
    int push(int item)
    {
        if(top==STACK_MAX_SIZE)return NULL_VALUE;
        data[top]=item;
        top++;
        return SUCCESS_VALUE;
    }
    int getTop()
    {
        return data[top-1];
    }
    int pop()
    {
        if(top==0)return NULL_VALUE;
        top--;
        int item=data[top];
        return item;
    }
    int isFull()
    {
        if(top==STACK_MAX_SIZE)return TRUE_VALUE;
        return FALSE_VALUE;
    }
    int isEmpty()
    {
        if(top==0)return TRUE_VALUE;
        return FALSE_VALUE;
    }
    int getLength()
    {
        return top;
    }
};
int getSum(int n)
{
    int sum=0,k;
    while(n!=0)
    {
        k=n%10;
        sum=sum+k;
        n=n/10;
    }
    return sum;
}
int main()
{
    Stack stk;
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        stk.push(getSum(a[i]));
    }
    printf("Sum of the numbers: \n");
    while(stk.isEmpty()==FALSE_VALUE)
    {
        printf("%d\n",stk.pop());
    }

}
