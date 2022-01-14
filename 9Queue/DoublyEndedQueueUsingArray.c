#include<stdio.h>
#include<stdlib.h>
struct DEQueue{
    int Front;
    int Rear;
    int size;
    int *A;
};
struct DEQueue* create(int size){
    struct DEQueue *dq=(struct DEQueue *)malloc(sizeof(struct DEQueue));
    dq->Front=dq->Rear=-1;
    dq->size=size;
    dq->A=(int *)malloc(size*sizeof(int));
    return dq;
}

void RearEnqueue(struct DEQueue *dq,int x){
    if(dq->Rear==dq->size-1)
        printf("Queue overflow ");
    else{
        dq->Rear++;
        dq->A[dq->Rear]=x;
    }
}

void FrontEnqueue(struct DEQueue *dq,int x){
    if(dq->Front==-1)
        printf("Queue underflow ");
    else{
        dq->A[dq->Front]=x;
        dq->Front--;
    }
}

int RearDequeue(struct DEQueue *dq){
    int x=-1;
    if(dq->Rear==-1)
        printf("Queue underflow ");
    else{
        x=dq->A[dq->Rear];
        dq->Rear--;
    }
    return x;
}

int FrontDequeue(struct DEQueue *dq){
    int x=-1;
    if(dq->Front==dq->Rear)
        printf("Queue underflow ");
    else{
        dq->Front++;
        x=dq->A[dq->Front];
    }
    return x;
}

void display(struct DEQueue *dq){
    int i=dq->Front+1;
    for(;i<dq->Rear+1;i++){
        printf("%d ",dq->A[i]);
    }
}

int main(){
    int size;
    struct DEQueue *dq;
    printf("Enter size : ");
    scanf("%d",&size);
    dq = create(size);

    printf("\nRear enqueue : ");
    RearEnqueue(dq,2);
    RearEnqueue(dq,4);
    RearEnqueue(dq,6);
    RearEnqueue(dq,8);

    display(dq);    

    printf("\nRear dequeue : ");
    RearDequeue(dq);
    RearDequeue(dq);
    
    display(dq);    

    printf("\nFront dequeue : ");
    FrontDequeue(dq);
    display(dq);    

    printf("\nFront enqueue : ");
    FrontEnqueue(dq,10);
    display(dq);    
    return 0;
}