#include<iostream>
#include<stdio.h>
#include<string.h>
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
int main()
{
    Stack stk;
    Stack stk2;
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
       stk.push(a[i]);
    }
    while(stk.isEmpty()==FALSE_VALUE)
    {
       stk2.push(stk.pop());
    }
    while(stk2.isEmpty()==FALSE_VALUE)
    {
        printf("%d ",stk2.pop());
    }
}
