struct Queue{
    int size;
    int front;
    int rear;
    struct Node **A;
};

void createQ(struct Queue *Q,int size)
{
    Q->size=size;
    Q->front=Q->rear=0;
    Q->A =(struct Node* *)malloc(size*sizeof(struct Node*));
}

void enqueueQ(struct Queue *Q,struct Node* value)
{
    if(Q->front==((Q->rear+1)%(Q->size)))
        printf("Queue is Overflow");
    else
        Q->A[(++(Q->rear))%(Q->size)]=value;
}

struct Node* dequeueQ(struct Queue *Q)
{
    struct Node* x=NULL;
    if(Q->front==Q->rear)
        printf("Queue is Underflow\n");
    else
        x=Q->A[(++(Q->front))%Q->size];
    return x;
}

int isEmptyQ(struct Queue Q)
{
    return Q.front==Q.rear;
}