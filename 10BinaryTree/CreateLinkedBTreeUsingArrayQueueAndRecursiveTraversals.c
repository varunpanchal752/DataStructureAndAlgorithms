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

void treeCreate()
{
    struct Node *p,*t;
    int x;
    struct Queue Q;
    createQ(&Q,100);
    printf("Enter value of Root Node: ");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=t->rchild=NULL;
    enqueueQ(&Q,root);

    while(!isEmptyQ(Q))
    {
        p=dequeueQ(&Q);
        printf("Enter left child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueueQ(&Q,t);
        }
         
        printf("Enter right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueueQ(&Q,t);
        }
    }
}

void preOrder(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void inOrder(struct Node *p)
{
    if(p)
    {
        inOrder(p->lchild);
        printf("%d ",p->data);
        inOrder(p->rchild);
    }
}

void postOrder(struct Node *p)
{
    if(p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ",p->data);
    }
}

int main()
{
    treeCreate();
    printf("PreOrder: ");
    preOrder(root);
    printf("\nInOrder: ");
    inOrder(root);
    printf("\nPostOrder: ");
    postOrder(root);
    printf("\n");
    return 0;
}