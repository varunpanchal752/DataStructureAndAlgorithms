#include<stdio.h>
#include<stdlib.h>
#include"ArrayStackC.h"

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void generateBSTFromPre(struct Node*p,int pre[],int preSize)
{
    int i=0;
    struct Stack st;
    createStk(&st,20);
    struct Node *t;
    if(preSize==0)
    {
        return;
    }

    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=pre[i++];
    p->lchild=p->rchild=NULL;
    root=p;

    while(i<preSize)
    {
        if(pre[i]<p->data)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=pre[i++];
            t->lchild=t->rchild=NULL;
            pushStk(&st,p);
            p->lchild=t;
            p=t;
        }
        else if(pre[i]>p->data) 
        {
            int a=isEmptyStk(st)? 32767:(((st.S)[st.top])->data);
            if(pre[i]<a)
            {
                t=(struct Node *)malloc(sizeof(struct Node));
                t->data=pre[i++];
                t->lchild=t->rchild=NULL;
                p->rchild=t;
                p=t;
            }   
            else
            {
                p=popStk(&st);
            }
        }
    }
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
    int pre[8]={30,20,10,15,25,40,50,45};
    int preSize=8;
    generateBSTFromPre(root,pre,preSize);
    
    inorder(root);
    return 0;
}