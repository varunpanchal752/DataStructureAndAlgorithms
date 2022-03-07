#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *lchild;    
    int data;
    struct Node *rchild;    
};
#include "CircularArrayQueueC.h"

struct Node* root=NULL;

int searchInorder(int inorder[],int inStart,int inEnd,int data)
{
    int i;
    for(i=inStart;i<=inEnd;i++)
    {
        if(inorder[i]==data)
            return i;
    }
    return -1;
}

struct Node * generateTreeFromTraversal(int inorder[],int preorder[],int inStart,int inEnd)
{   
    static int preIndex=0;
    int splitIndex;
    
    if(inStart>inEnd)
    {
        return NULL;
    }

    struct Node *root = (struct Node*)malloc(sizeof(struct Node));
    root->data=preorder[preIndex++];
    root->lchild=root->rchild=NULL;

    if(inStart==inEnd)
    {   
        return root;
    }

    splitIndex = searchInorder(inorder,inStart,inEnd,root->data);
    root->lchild = generateTreeFromTraversal(inorder,preorder,inStart,splitIndex-1);
    root->rchild = generateTreeFromTraversal(inorder,preorder,splitIndex+1,inEnd);
    return root;
}   

void iLevelOrder(struct Node *root)
{
    struct Queue Q;
    createQ(&Q,100);
    printf("%d ",root->data);
    enqueueQ(&Q,root);
    while(!isEmptyQ(Q))
    {
        root=dequeueQ(&Q);
        if(root->lchild!=NULL)
        {
            printf("%d ",root->lchild->data);
            enqueueQ(&Q,root->lchild);
        }   
        if(root->rchild!=NULL)
        {
            printf("%d ",root->rchild->data);
            enqueueQ(&Q,root->rchild);
        }
    }
}


int main()
{
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    
    struct Node *root = generateTreeFromTraversal(inorder,preorder,0,sizeof(inorder)/sizeof(inorder[0])-1);
    
    printf("Level order: ");
    iLevelOrder(root);
    printf("\n");
    return 0;
}