#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Node *root=NULL;

void iInsert(int key)
{
    struct Node *t,*p,*q;
    if(root==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        root=t;
    }
    else
    {
        p=root;
        while(p)
        {
            if(key<p->data)
            {
                q=p;
                p=p->lchild;
            }
            else if(key>p->data)
            {
                q=p;
                p=p->rchild;
            }
            else
                return;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        if(key<q->data)
            q->lchild=t;
        else if(key>q->data)
            q->rchild=t;
    }
}

int search(int key)
{
    struct Node *p=root;
    if(p==NULL)
        return 0;
    while(p)
    {
        if(key<p->data)
            p=p->lchild;
        else if(key>p->data)
            p=p->rchild;
        else
            return 1;    
    }
    return 0;
}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

int main()
{
    iInsert(10);
    iInsert(1);
    iInsert(0);
    iInsert(5);

    inorder(root);

    if(search(1))
        printf("\nElement is found");
    else
        printf("\nElement is not found");

    return 0;
}