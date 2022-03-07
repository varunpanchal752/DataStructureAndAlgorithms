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

int degree0(struct Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=degree0(p->lchild);
        y=degree0(p->rchild);
        if(!p->lchild && !p->rchild)
            return x+y+1;
        else
            return x+y;
    }
    else
        return 0;
}

int degree1(struct Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=degree1(p->lchild);
        y=degree1(p->rchild);
        if((p->lchild && !p->rchild) || (!p->lchild && p->rchild))
            return x+y+1;
        else
            return x+y;
    }
    else
        return 0;
}

int degree1And2(struct Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=degree1And2(p->lchild);
        y=degree1And2(p->rchild);
        if(p->lchild || p->rchild)
            return x+y+1;
        else
            return x+y;
    }
    else
        return 0;
}

int degree2(struct Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=degree2(p->lchild);
        y=degree2(p->rchild);
        if(p->lchild && p->rchild)
            return x+y+1;
        else
            return x+y;
    }
    else
        return 0;
}

int height(struct Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    else
        return 0;
}

int sum(struct Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=sum(p->lchild);
        y=sum(p->rchild);
        return x+y+(p->data);
    }
    else
        return 0;
}

int main()
{
    treeCreate();
    printf("\nNo of Nodes with degree 0 is: ");
    printf("%d",degree0(root));
    printf("\nNo of Nodes with degree 1 is: ");
    printf("%d",degree1(root));
    printf("\nNo of Nodes with degree 1 as well as 2 is: ");
    printf("%d",degree1And2(root));
    printf("\nNo of Nodes with degree 2 is: ");
    printf("%d",degree2(root));
    printf("\nHeight Of tree is: ");
    printf("%d",height(root));
    printf("\nSum Of Nodes of tree is: ");
    printf("%d",sum(root));
    printf("\n");
    return 0;
}