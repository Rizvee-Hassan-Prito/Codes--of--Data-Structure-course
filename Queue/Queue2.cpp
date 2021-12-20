#include<iostream>
#include<stdio.h>
#include<string.h>
#define STACK_MAX_SIZE 50
#define QUEUE_MAX_SIZE 50
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define TRUE_VALUE 1
#define FALSE_VALUE 0

class Queue
{
private:
    int data[QUEUE_MAX_SIZE];
    int frnt,rear;
    int length;
public:
    Queue()
    {
         frnt=0,rear=0;
         length=0;
    }
    int enqueue(int item)
    {
        if(length==STACK_MAX_SIZE)return NULL_VALUE;
        data[frnt]=item;
        frnt++;
        length++;
        return SUCCESS_VALUE;
    }
    int dequeue()
    {
       if(length==0)return NULL_VALUE;
        int item=data[rear];
        rear++;
        length--;
        return item;
    }
    int isFull()
    {
        if(length==STACK_MAX_SIZE)return TRUE_VALUE;
        return FALSE_VALUE;
    }
    int isEmpty()
    {
        if(length==0)return TRUE_VALUE;
        return FALSE_VALUE;
    }
    int getLength()
    {
        return length;
    }
};
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
    Queue que;
    Stack stk;
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
       que.enqueue(a[i]);
    }
    while(que.isEmpty()==FALSE_VALUE)
    {
       stk.push(que.dequeue());
    }
    while(stk.isEmpty()==FALSE_VALUE)
    {
        que.enqueue(stk.pop());
    }
    while(que.isEmpty()==FALSE_VALUE)
    {
        printf("%d ",que.dequeue());
    }
}

