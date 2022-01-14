#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct DEQueue
{
    int size;
    struct Node *Front;
    struct Node *Rear; 
};

void create(struct DEQueue *dq){
    printf("Enter size : ");
    scanf("%d",&(dq->size));
    dq->Front=dq->Rear=NULL;
}

void frontEnqueue(struct DEQueue *dq,int x){
    if(dq->size==0){
        printf("Queue is Overflow");
        return;
    }
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(dq->Front==NULL){
        dq->Front=dq->Rear=t;
    }
    else{
        t->next=dq->Front;
        dq->Front=t;
    }
    dq->size--;
}

void rearEnqueue(struct DEQueue *dq,int x){
    if(dq->size==0){
        printf("Queue is Overflow");
        return;
    }
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(dq->Front==NULL){
        dq->Front=dq->Rear=t;
    }
    else{
        dq->Rear->next=t;
        dq->Rear=t;
    }
    dq->size--;
}

int rearDequeue(struct DEQueue *dq){
    int x=-1;
    struct Node *p=dq->Front;
    if(dq->Front==NULL){
        printf("Queue is underflow");
        return x;
    }
    else{
        x=dq->Rear->data;
        if(p->next==NULL){
            free(dq->Rear);
            p=dq->Front=dq->Rear=NULL;
        }
        else{
            while(p->next!=dq->Rear){
                p=p->next;
            }
            p->next=NULL;
            free(dq->Rear);
            dq->Rear=p;
        }
    }
    dq->size++;
    return x;
}

int frontDequeue(struct DEQueue *dq){
    int x=-1;
    struct Node *p=dq->Front;
    if(dq->Front==NULL){
        printf("Queue is underflow");
        return x;
    }
    else{
        x=dq->Front->data;
        dq->Front=p->next;
        free(p);
    }
    dq->size++;
    return x;
}

void display(struct DEQueue *dq){
    struct Node *p=dq->Front;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    struct DEQueue dq;
    create(&dq);

    printf("\nRear enqueue : ");
    rearEnqueue(&dq,2);
    rearEnqueue(&dq,4);
    rearEnqueue(&dq,6);
    rearEnqueue(&dq,8);
    display(&dq);

    printf("\nFront dequeue : ");
    frontDequeue(&dq);
    frontDequeue(&dq);
    frontDequeue(&dq);
    display(&dq);
    
    printf("\nFront enqueue : ");
    frontEnqueue(&dq,10);
    frontEnqueue(&dq,12);
    display(&dq);
  
    printf("\nRear dequeue : ");
    rearDequeue(&dq);
    display(&dq);
    return 0;
}