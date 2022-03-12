#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root=NULL;

int nodeHeight(struct Node *p)
{
    int hl,hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl > hr ? hl+1 : hr+1;
}

int balanceFactor(struct Node *p)
{
    int hl,hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl-hr;
}

struct Node* LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if(root==p)
        root=pl;
        
    return pl;
}

struct Node* LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    plr->height = nodeHeight(plr);

    if(root==p)
        root=plr;

    return plr;
}

struct Node* RRRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    p->rchild = prl;
    pr->lchild = p;

    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    if(root==p)
        root=pr;

    return pr;
}

struct Node* RLRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;

    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);
    prl->height = nodeHeight(prl);

    if(root==p)
        root=prl;

    return prl;
}

struct Node* rInsert(struct Node *p,int key)
{
    struct Node *t;
    if(p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key < p->data)
        p->lchild = rInsert(p->lchild,key);
    else if(key > p->data)
        p->rchild = rInsert(p->rchild,key);
    
    p->height = nodeHeight(p);

    if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}

int main()
{
    root = rInsert(root,50);
    rInsert(root,10);
    rInsert(root,20);
    printf("%d",root->data);
    return 0;
}