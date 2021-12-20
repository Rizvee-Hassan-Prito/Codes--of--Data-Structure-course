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

int deleteItem(int item)
{
	struct listNode *temp, *prev ;
	temp = head ; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) break ;
		prev = temp;
		temp = temp->next ; //move to next node
	}
	if (temp == 0) return NULL_VALUE ; //item not found to delete
	if (temp == head) //delete the first node
	{
		head= head->next ;
		free(temp) ;
	}
	else
	{
		prev->next = temp->next ;
		free(temp);
	}
	return SUCCESS_VALUE ;
}

struct listNode * searchItem(int item)
{
	struct listNode * temp ;
	temp = head; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) return temp ;
		temp = temp->next ; //move to next node
	}
	return 0 ; //0 means invalid pointer in C, also called NULL value in C
}
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

int insertLast(int item)
{
    struct listNode * temp,* last,* last2;
    last=(struct listNode*) malloc (sizeof(struct listNode)) ;
    last2=(struct listNode*) malloc (sizeof(struct listNode)) ;
    last2->next=0;
    last2->item=item;
    temp = head;
    while(temp!=0)
    {
        last=temp;
        temp = temp->next;
    }
    last->next=last2;
    return SUCCESS_VALUE ;
}

int insertAfter(int oldItem, int newItem) //Inserts newItem after oldItem, if oldItem is not present, returns NULL VALUE
{
    struct listNode * temp, * mid, *head1;
    mid = (struct listNode*) malloc (sizeof(struct listNode)) ;
    temp = head;
    mid->item=newItem;
    while(temp->item!=oldItem)
    {
        temp = temp->next;
    }
    if (temp == 0) return NULL_VALUE ;
    mid->next=temp->next;
    temp->next=mid;
}

int deleteLast()
{
    struct listNode * temp ;
	temp = head; //start at the beginning
	while (temp->next!= 0)
	{
		temp = temp->next ;
	}
	deleteItem(temp->item);
    //Use deleteItem function to delete the last item of the list
}

int deleteFirst()
{
    deleteItem(head->item);
    //Use deleteItem function to delete the first item of the list
}

void deleteDuplicate()
{
    struct listNode *temp, *prev,* temp3;
    int c=0,f;
    temp=head;
    prev=head;
    while(temp!=0)
          {
             temp3=temp->next;
             c=0;
             while(temp3!=0)
             {
               if(temp3->item==temp->item)
               {
                   c=1;f=temp->item;
                   prev->next=temp3->next;
                   temp3=temp3->next;
               }
               else
               {
                   prev=temp3;
                   temp3=temp3->next;
               }
            }
            temp=temp->next;
            prev=temp;
            if(c!=0){deleteItem(f);}
          }
}

void sufixSum(int item)
{
    struct listNode * temp ;
	temp = head;
	int sum=0;
	while (temp->item!= item)
	{
	    //sum=sum+temp->item;
		temp = temp->next ; //move to next node
	}
	temp=temp->next;
	while (temp!= 0)
	{
	    sum=sum+temp->item;
		temp = temp->next ; //move to next node
	}
	printf("Sum: %d\n",sum);
    //Print the summation of the items that are behind the item in the list.
    //If the list is 10->21->30->15->23. Then sufixSum(30) will return 38.
}

int main()
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Insert at last. 5. Insert After 6. delete Last 7. delete First \n");
        printf("8. Print. 9. exit. 10. prefix sum\n");

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
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4){
            int item;
            scanf("%d", &item);
            insertLast(item);
        }
        else if(ch==5){
            int oldItem, newItem;
            scanf("%d %d",&oldItem, &newItem);
            insertAfter(oldItem,newItem);
        }
        else if(ch==6){
            deleteLast();
        }
        else if(ch==7){
            deleteFirst();
        }
        else if(ch==8)
        {
            printList();
        }
        else if(ch==9)
        {
            break;
        }
        else if(ch==10)
        {
            int item;
            scanf("%d",&item);
            sufixSum(item);
        }
        else if(ch==11){
            deleteDuplicate();
        }
    }

}

