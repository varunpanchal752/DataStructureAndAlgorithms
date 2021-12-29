#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    int i;
    struct Node *t,*last;

    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=first;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        t->next->prev=t;
        t->prev=last;
        last=t;
    }
}

void Display(struct Node *q){
    struct Node *p=q;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=q);
    printf("\n");
}

int Length(struct Node *q){
    int len=0;
    struct Node *p=q;
    do{
        len++;
        p=p->next;
    }while(p!=q);
    return len;
}

void Insert(struct Node *p,int x,int index){
    int i;
    struct Node *t;
    if(p==NULL && index==0){
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=x;
        p->next=p->prev=p;
        first=p;
        return;
    }

    if(index<0 || index>Length(p))
        return;
    if(index==0 || index==Length(p)){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p;
        t->prev=p->prev;
        p->prev=t;
        t->prev->next=t;
    }
    else{
        for(i=0;i<index-1;i++) 
            p=p->next;
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        t->prev=p;
        p->next->prev=t;
        p->next=t;
    } 
}

int Delete(struct Node *p,int index){
    int i,x=-1;
    if(index<1 || index>Length(p))
        return -1;
    if(index==1){
        x=p->data;
        p->next->prev=p->prev;
        p->prev->next=p->next;
        first=p->next;   
    }
    else{        
        for(i=0;i<index-1;i++)
            p=p->next;
        x=p->data;
        p->next->prev=p->prev;
        p->prev->next=p->next;
    }
    free(p);
    return x;
}

int main(){
    int A[]={10,20,30,40,50};
    create(A,5);
    // Insert(first,35,0);
    printf("\n%d\n",Delete(first,5));
    Display(first);
    return 0;
}