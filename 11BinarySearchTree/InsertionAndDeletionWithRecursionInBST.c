#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Node *root=NULL;

struct Node* rInsert(struct Node *p,int key)
{
    struct Node *t;
    if(p==NULL)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
        p->lchild=rInsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=rInsert(p->rchild,key);
    return p;
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

struct Node* inSuccessor(struct Node *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;
    return p;
}

struct Node* inPredecessor(struct Node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    return p;
}   

int Height(struct Node *p)
{
    int x,y;
    if(p)
    {
        x=Height(p->lchild);
        y=Height(p->rchild);
        return x>y?x+1:y+1;
    }
    else
        return 0;
}

struct Node* delete(struct Node*p,int key)
{
    struct Node *q=NULL;
    if(!p)
        return NULL;
    if(p->data==key && p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root) 
            root=NULL;
        free(p);
        return NULL;
    }
    else
    {
        if(key<p->data)
        {
            p->lchild=delete(p->lchild,key);
        }
        else if(key>p->data)
        {
            p->rchild=delete(p->rchild,key);
        }
        else
        {
            if(Height(p->lchild)>Height(p->rchild))
            {
                q=inPredecessor(p->lchild);
                p->data=q->data;
                p->lchild=delete(p->lchild,q->data);
            }
            else
            {
                q=inSuccessor(p->rchild);
                p->data=q->data;
                p->rchild=delete(p->rchild,q->data);
            }
        }
        return p;
    }
}

int main()
{
    root=rInsert(root,20);
    rInsert(root,4);
    rInsert(root,10);
    rInsert(root,1);

    inorder(root);
    printf("\n");

    printf("\nAfter Deleting elements are : ");
    delete(root,10);
    
    inorder(root);
    return 0;
}