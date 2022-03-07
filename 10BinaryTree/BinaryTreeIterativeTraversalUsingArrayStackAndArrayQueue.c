#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *lchild;    
    int data;
    struct Node *rchild;    
};
#include "CircularArrayQueueC.h"
#include "ArrayStackC.h"

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

void iPreOrder(struct Node *p)
{
    struct Stack st;
    createStk(&st,100);
    while(p!=NULL || !isEmptyStk(st))
    {
        if(p!=NULL)
        {
            printf("%d ",p->data);
            pushStk(&st,p);
            p=p->lchild;
        }   
        else
        {
            p=popStk(&st);
            p=p->rchild;
        }
    }
}

void iInOrder(struct Node *p)
{
    struct Stack st;
    createStk(&st,100);
    while(p || !isEmptyStk(st))
    {
        if(p)
        {
            pushStk(&st,p);
            p=p->lchild;
        }   
        else
        {
            p=popStk(&st);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }
}

void iPostOrder(struct Node *p)
{
    long int temp;
    struct Stack st;
    createStk(&st,100);
    while(p!=NULL || !isEmptyStk(st))
    {
        if(p!=NULL)
        {
            pushStk(&st,p);
            p=p->lchild;
        }   
        else
        {
            temp=(long int)popStk(&st);
            if(temp>0)
            {
                p=((struct Node*)temp)->rchild;
                temp=-1*temp;
                pushStk(&st,((struct Node*)temp));
            }
            else
            {
                temp=-1*temp;
                printf("%d ",((struct Node *)temp)->data);
                p=NULL;
            }
        }
    }
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
    treeCreate();
    printf("PreOrder: ");
    iPreOrder(root);
    printf("\nInOrder: ");
    iInOrder(root);
    printf("\nPostOrder: ");
    iPostOrder(root);
    printf("\nLevelOrder: ");
    iLevelOrder(root);
    printf("\n");
    return 0;
}