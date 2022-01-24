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
    char data[STACK_MAX_SIZE];
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
        char item=data[top];
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
    char c[STACK_MAX_SIZE],d;
    scanf("%s",c);
    for(int i=0;i<strlen(c);i++)
    {
       if(c[i]=='('||c[i]=='{'||c[i]=='[')
        {
          stk.push(c[i]);
        }
       else if(c[i]==')'||c[i]=='}'||c[i]==']')
       {
           char d=stk.pop();
           if(c[i]==')'&&d=='(')
            continue;
           else if(c[i]=='}'&&d=='{')
            continue;
           else if(c[i]==']'&&d=='[')
            continue;
           else{printf("Invalid.");return 0;}

       }
    }
    if(stk.isEmpty()==1){
        printf("Valid.");
    }
    else{printf("Invalid.");}

}

