#include<stdio.h>
#include<stdlib.h>
#define FALSE_VALUE 0
#define TRUE_VALUE 1

struct treeNode
{
    int data;
    struct treeNode * left; //points to left child
    struct treeNode * right; //points to right child
};

struct treeNode * root;


void initializeTree()
{
    root = 0;
}

/****** Complete the following functions using Loop ******/
struct treeNode * searchItem(int item)
{
    struct treeNode * root2=root;
    while(root2!=0)
    {
    if(root2->data==item)
    {
        return root2;
    }
    if(item>=root2->data)
    {
        root2=root2->right;
    }
    else
    {
        root2=root2->left;
    }
    }
    return FALSE_VALUE;
};

int insertItem(int item)
{
    struct treeNode *root2,*root3;
    root2 = (struct treeNode*) malloc (sizeof(struct treeNode));
    root3=(struct treeNode*) malloc (sizeof(struct treeNode));
    root2->data=item;
    root2->right=0;
    root2->left=0;
    root3=root;
    if(root3==0)
    {
        root=root2;
        return TRUE_VALUE;
    }
    while(1)
    {
        if(root3->data<=item && root3->right==0){root3->right=root2;return TRUE_VALUE;}
        else if(root3->data<=item && root3->right!=0){root3=root3->right;}
        else if(root3->data>item && root3->left==0){root3->left=root2;return TRUE_VALUE;}
        else if(root3->data>item && root3->left!=0){root3=root3->left;}
    }
    //If success return TRUE_VALUE, else return FALSE_VALUE
}

void deleteItem(int item)
{
     struct treeNode *root2=root,*root3;
     while(root2!=0)
     {
     if(root2->data==item)
     {
         if(root2->right==0 && root2->left==0)
         {
             if(root->data==item)
             {
                 root=0;
                 break;
             }
             if(root3->right==root2){root3->right=0;}
             else{root3->left=0;}
             break;
         }
         else if(root2->right==0)
         {
             if(root->data==item)
             {
                 root=root2->left;
                 break;
             }
             if(root3->right==root2){root3->right=root2->left;}
             else{root3->left=root2->left;}
             break;
         }
         else if(root2->left==0)
         {
             if(root->data==item)
             {
                 root=root2->right;
                 break;
             }
             if(root3->right==root2){root3->right=root2->right;}
             else{root3->left=root2->right;}
             break;
         }
         else if(root2->right!=0 && root2->left!=0)
         {
             struct treeNode *replace=root2->left,*replace2=root2,*delete1=root2,*n;
             root2=root2->left;
             int max=0;
             while(root2!=0){
             if(root2->data>max)
                {
                    n=delete1;
                    max=root2->data;
                    replace=root2;
                }
                delete1=root2;
                root2=root2->right;
             }
             if(root->data==item)
             {
                 root->data=replace->data;
                 if(replace->left==0 && n->right==replace)
                 {n->right=0;}
                 else if(replace->left!=0 && n->right==replace)
                 {n->right=replace->left;replace->left=0;}
                 else if(replace->left!=0 && n->right!=replace){n->left=replace->left;replace->left==0;}
                 else if(replace->right==0 && replace->left==0){n->left=0;}
                 break;
             }
             if(root3->right==replace2){root3->right->data=replace->data;}
             else{root3->left->data=replace->data;}
             if(replace2->left==replace){replace2->left=replace2->left->left;}
             else{
                    if(n->right->left!=0){n->right=n->right->left;}
                    else{n->right=0;}
             }
             break;
         }
     }
     if(root2->data<=item)
     {
         root3=root2;
         root2=root2->right;
     }
     else
     {
         root3=root2;
         root2=root2->left;
     }
     }
}

int calcLevel(int item)
{
    struct treeNode * root2=root;
    int i=0;
    while(root2!=0)
    {
    if(root2->data==item)
    {
        return i;
    }
    if(item>=root2->data)
    {
        i++;
        root2=root2->right;
    }
    else
    {
        i++;
        root2=root2->left;
    }
    }
    return TRUE_VALUE;
    //return level/depth of an item in the tree
}

int getMinItem() // return the minimum item in the tree
{
  struct treeNode * root2=root;
  while(root2->left!=0)
  {
      root2=root2->left;
  }
  return root2->data;
}

int getMaxItem() // return the maximum item in the tree
{
  struct treeNode * root2=root;
  while(root2->right!=0)
  {
      root2=root2->right;
  }
  return root2->data;
}

void TreeInOrder(struct treeNode *root)
{
     if(root==0)return;
     TreeInOrder(root->left);
     printf("%d->", root->data);
     TreeInOrder(root->right);
}

int main(void)
{
    initializeTree();
    while(1)
    {
        printf("\n1.Insert item. 2.Delete item. 3.Search item. \n");
        printf("4.Print level of an item. \n");
        printf("5.Get Minimum  6.Get Maximum \n");
        printf("7.Print\n");

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
            struct treeNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            int level = calcLevel(item);
            printf("Level of %d = %d\n", item, level);
        }
        else if(ch==5)
        {
            printf("Minimum: %d\n",getMinItem());
        }
        else if(ch==6)
        {
            printf("Maximum: %d\n",getMaxItem());
        }
        else if(ch==7)
        {
            TreeInOrder(root);
        }
    }

}

