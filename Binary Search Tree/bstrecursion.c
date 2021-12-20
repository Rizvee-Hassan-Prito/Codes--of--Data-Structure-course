#include<stdio.h>
#include<stdlib.h>
#define FALSE_VALUE 0
#define TRUE_VALUE 1

struct treeNode
{
    int item;
    struct treeNode * left; //points to left child
    struct treeNode * right; //points to right child
};

struct treeNode * root;

void initializeTree()
{
    root = 0;
}


struct treeNode * searchItem(struct treeNode * node, int item)
{
    if(node==0){return 0;}
    else if(node->item==item)
    {
        return node;
    }
    else if(item>=node->item)
    {
        searchItem(node->right,item);
    }
    else
    {
        searchItem(node->left,item);
    }
};

struct treeNode * searchPrev(struct treeNode * node,int item)
{
    // Return the parent node of the item using recursion
    if(node==NULL){return node;}
    else if(node->right->item==item && node->right!=NULL)
    {
        return node;
    }
    else if(node->left->item==item && node->left!=NULL )
    {
        return node;
    }
    else if(item>=node->item)
    {
        searchPrev(node->right, item);
    }
    else
    {
        searchPrev(node->left,item);
    }
};

struct treeNode * makeTreeNode(int item)
{
    struct treeNode * node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};

int insertItem(struct treeNode * node, int item)
{
    // Insert item in the tree using recursion
    if(node==0)
    {
        node=makeTreeNode(item);
        return 0;
    }
    if(node->item<=item)
    {
        insertItem( node->right, item);
    }
    else{insertItem( node->left, item);}
}


int calcNodeHeight(struct treeNode * node)
{
    // return height (maximum distance from node to leaf + 1) using recursion
    if(node == NULL)
       return 0;
    else
    {
       int lt=0;
       int rt=0;
       lt = calcNodeHeight(node -> left);
       rt = calcNodeHeight(node -> right);
       if(lt > rt)
        {
           return lt + 1;

        }
        else {return rt + 1;}
    }
}


int calcHeight(int item) //return height of an item in the tree
{
    // return height of an item using calcNodeHeight function
    return calcNodeHeight(searchItem(root,item));
}

int getSize(struct treeNode * node)
{
    // return size of the tree with node(argument) as root using recursion
     if(node==0)return 0;
     return getSize(node->left)+getSize(node->right)+1;
}

int calcNodeDepth(struct treeNode * node)
{
    //calculate depth of level of a node using recursion
    if (node == 0) {
        return -1; // an empty tree  has height −1
    } else {
        // compute the depth of each subtree
        int ltD = calcNodeDepth(node->left);
        int rtD = calcNodeDepth(node->right);
        // use the larger one
        if (ltD > rtD )
            return (ltD + 1);
        else
            return (rtD + 1);
    }
}

struct treeNode *findLCA(struct treeNode *node,int item1,int item2)
{
    //Find lowest common ancestors of item1 and item2 using recursion
    if (node == 0) return node;
    if (node->item > item1 && node->item > item2)
        {return findLCA(node->left, item1, item2);}
    if (node->item < item1 && node->item < item2)
        {return findLCA(node->right, item1, item2);}
    return node;
}

int calcDepth(int item)
{
    //Return depth or level of an item using calcNodeDepth function
    return calcNodeDepth(searchItem(root,item));
}


int deleteItem(int item)
{
    //write your code from previous assignment here, you do not need to implement using recursion
    struct treeNode *root2=root,*root3;
     while(root2!=0)
     {
     if(root2->item==item)
     {
         if(root2->right==0 && root2->left==0)
         {
             if(root->item==item)
             {
                 root=0;
                 return 0;
             }
             if(root3->right==root2){root3->right=0;}
             else{root3->left=0;}
             return 0;
         }
         else if(root2->right==0)
         {
             if(root->item==item)
             {
                 root=root2->left;
                 return 0;
             }
             if(root3->right==root2){root3->right=root2->left;}
             else{root3->left=root2->left;}
             return 0;
         }
         else if(root2->left==0)
         {
             if(root->item==item)
             {
                 root=root2->right;
                 return 0;
             }
             if(root3->right==root2){root3->right=root2->right;}
             else{root3->left=root2->right;}
             return 0;
         }
         else if(root2->right!=0 && root2->left!=0)
         {
             struct treeNode *replace=root2->left,*replace2=root2,*delete1=root2,*n;
             root2=root2->left;
             int max=0;
             while(root2!=0){
             if(root2->item>max)
                {
                    n=delete1;
                    max=root2->item;
                    replace=root2;
                }
                delete1=root2;
                root2=root2->right;
             }
             if(root->item==item)
             {
                 root->item=replace->item;
                 if(replace->left==0 && n->right==replace)
                 {n->right=0;}
                 else if(replace->left!=0 && n->right==replace)
                 {n->right=replace->left;replace->left=0;}
                 else if(replace->left!=0 && n->right!=replace){n->left=replace->left;replace->left==0;}
                 else if(replace->right==0 && replace->left==0){n->left=0;}
                 return 0;
             }
             if(root3->right==replace2){root3->right->item=replace->item;}
             else{root3->left->item=replace->item;}
             if(replace2->left==replace){replace2->left=replace2->left->left;}
             else{
                    if(n->right->left!=0){n->right=n->right->left;}
                    else{n->right=0;}
             }
             return 0;
         }
     }
     if(root2->item<=item)
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
     return -1;
}

struct treeNode *getMinItem(struct treeNode * node)
{
    //return the minimum item in the tree using recursion
    if(node->left==0)return node;
    return getMinItem(node->left);
}

struct treeNode *getMaxItem(struct treeNode * node)
{
    //return the maximum item in the tree using recursion
    if(node->right==0)return node;
    return getMaxItem(node->right);
}

int rangeSearch(struct treeNode * node, int leftBound, int rightBound)
{
    //returns number of items in the range of leftBound and rightBound using recursion
    if (node == 0) {
        return 0;
    }
    else if (node->item == leftBound && node->item == rightBound) {
        return 1;
    }
    else if (node->item >= leftBound && node->item <= rightBound) {
        return 1 + rangeSearch(node->left, leftBound, rightBound) + rangeSearch(node->right, leftBound, rightBound);
    }
    else if (node->item > leftBound && node->item > rightBound) {
        return rangeSearch(node->left, leftBound, rightBound);
    }
    else {
    return rangeSearch(node->right, leftBound, rightBound);
    }
}

int findInOrderSuccessor(int item)
{
    //return In order successor of the item in the tree (You need not use recursion)
    struct treeNode *r=root,*r1;
    while(r!=0)
    {
        if(item==r->item)
        {
            if(r->right!=0 && r->right->left==0)
                return r->right->item;
            else if(r->right!=0 && r->right->left!=0)
                return r->right->left->item;
            else if(r->right==0 && r1->left==r)
                {return r1->item;}
            else if(r1->right==r && r->right==0 && r->left==0 && root->item>r->item)
                {return root->item;}
            else
                {return NULL;}
        }
        if(item>r->item)
        {
             r1=r;
            r=r->right;
        }
        else
           {
            r1=r;
            r=r->left;
           }
    }
     return NULL;
}

void printInOrder(struct treeNode * node, int height)
{
    if(node==0) return;

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);

    //print right sub-tree
    printInOrder(node->right, height-1);
}

void printPreOrder(struct treeNode * node, int height)
{
    //Write your code using recursion to print the tree in pre-order
    if(node==0) return;

    //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print right sub-tree
    printInOrder(node->right, height-1);

}

void printPostOrder(struct treeNode * node, int height)
{
    //Write your code using recursion to print the tree in post-order
     if(node==0) return;

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print right sub-tree
    printInOrder(node->right, height-1);

    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);
}

int main(void)
{
    initializeTree();
    while(1)
    {
        printf("\n");
        printf("1. Insert item. 2. Previous item. 3. Search item. \n");
        printf("4. Print height of tree. 5. Print height of an item. \n");
        printf("6. PrintInOrder. 7. PrintPreOrder 8. PrintPostOrder\n");
        printf("9. Print depth of an item. 10.Print size 11.Get Minimum 12.Get Maximum \n");
        printf("13.Delete item 14.RangeSearch 15.findLCA  16.findInorderSuccessor 17.Exit\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(root, item);
            //insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            struct treeNode * res = searchPrev(root, item);
            if(res==0) printf("No parent found.\n");
            else printf("Parent Node: %d\n",res->item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int height = calcNodeHeight(root);
            printf("Height of tree = %d\n", height);
        }
        else if(ch==5)
        {
            int item;
            scanf("%d", &item);
            int height = calcHeight(item);
            printf("Height of %d = %d\n", item, height);
        }
        else if(ch==6)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==7)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printPreOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==8)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printPostOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==9)
        {
            int item;
            scanf("%d", &item);
            int depth = calcDepth(item);
            printf("Depth of %d = %d\n", item, depth);
        }
        else if(ch==10)
        {
            printf("Size of tree is %d\n",getSize(root));
        }
        else if(ch==11)
        {
            printf("%d\n",getMinItem(root));
        }
        else if(ch==12)
        {
            printf("%d\n",getMaxItem(root));
        }
        else if(ch==13)
        {
            int item;
            scanf("%d",&item);
            int func = deleteItem(item);
            if(func==-1) printf("Item not present\n");
            else printf("Item Deleted.\n");
        }
        else if(ch==14)
        {
            int leftBound,rightBound;
            scanf("%d %d",&leftBound,&rightBound);
            int num = rangeSearch(root,leftBound,rightBound);
            printf("%d\n",num);
        }
        else if(ch==15)
        {
            int item1,item2;
            scanf("%d %d",&item1,&item2);
            struct treeNode *node=findLCA(root,item1,item2);
            printf("LCA is: %d\n",node->item);
        }
        else if(ch==16)
        {
            int item;
            scanf("%d",&item);
            printf("In order successor of %d is: %d\n",item,findInOrderSuccessor(item));
        }
        else if(ch==17)
        {
            break;
        }
    }

}




/*int insertItem(int item)
{
    struct treeNode *root2,*root3;
    root2 = (struct treeNode*) malloc (sizeof(struct treeNode));
    root3=(struct treeNode*) malloc (sizeof(struct treeNode));
    root2->item=item;
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
        if(root3->item<=item && root3->right==0){root3->right=root2;return TRUE_VALUE;}
        else if(root3->item<=item && root3->right!=0){root3=root3->right;}
        else if(root3->item>item && root3->left==0){root3->left=root2;return TRUE_VALUE;}
        else if(root3->item>item && root3->left!=0){root3=root3->left;}
    }
    //If success return TRUE_VALUE, else return FALSE_VALUE
}*/

