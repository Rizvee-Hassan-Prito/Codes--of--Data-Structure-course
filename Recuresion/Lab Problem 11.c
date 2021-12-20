#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * head;

void initializeList()
{
    head = 0;//initially set to NULL
}

int insertItem(int item) //insert at the beginning
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->next = head; //point to previous first node
	head = newNode ; //set list to point to newnode as this is now the first node
	return SUCCESS_VALUE ;
}

struct listNode * revList(struct listNode *node)
{
    if(node->next==0)
    {
        head=node;
        return node;
    }
    struct listNode * prev=revList(node->next);
    prev->next=node;
    node->next=0;
    return node;
};

void printList()
{
    struct listNode * temp;
    temp = head;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item.\n");
        printf("2. Print. 3.Reverse list\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            printList();
        }
        else if(ch==3)
        {
            revList(head);
        }
    }

}


