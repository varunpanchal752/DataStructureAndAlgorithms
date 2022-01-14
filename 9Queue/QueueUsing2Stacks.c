#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *S;
};
void create(struct Stack *st)
{
    printf("Enter Size : ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}
void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}
void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
int pop(struct Stack *st)
{
    int x = -1;

    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}
int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid Index \n");
    else 
        x = st.S[st.top - index + 1];

    return x;
}
int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
int isFull(struct Stack st)
{
    return st.top == st.size - 1;
}
int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top];
    return -1;
}

struct Queue
{
    struct Stack st1;
    struct Stack st2;
};

void createQ(struct Queue *q){
    create(&(q->st1));
    create(&(q->st2));
}

void enqueueQ(struct Queue *q,int x){
    push(&(q->st1), x);
}

int dequeueQ(struct Queue *q){
    if(isEmpty(q->st2)){
        if(isEmpty(q->st1)){
            printf("Queue is empty");
            return -1;
        }
        else{
            while(!isEmpty(q->st1)){
                push(&(q->st2),pop(&(q->st1)));
            }   
        }
    }    
    return pop(&(q->st2));
}

int main()
{
    struct Queue q;

    createQ(&q);
    enqueueQ(&q,2);
    enqueueQ(&q,4);
    enqueueQ(&q,6);
    enqueueQ(&q,8);

    printf("\npopped : %d\n",dequeueQ(&q));
    printf("\npopped : %d\n",dequeueQ(&q));

    return 0;
}