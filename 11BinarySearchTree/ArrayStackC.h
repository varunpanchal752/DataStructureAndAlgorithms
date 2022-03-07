struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void createStk(struct Stack *st,int size)
{
    st->size=size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size * sizeof(struct Node*));
}

void pushStk(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node* popStk(struct Stack *st)
{
    struct Node *x = NULL;

    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int isEmptyStk(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
