#include<stdio.h>
#include<stdlib.h>

//Linked List code starts here.
struct Node{
    int value;
    struct Node* next;
};

void sortedInsert(struct Node **H,int key)
{
    struct Node *p=*H,*q=NULL,*temp=(struct Node*)malloc(sizeof(struct Node));
    temp->value=key;
    temp->next=NULL;
    
    if(*H==NULL)//struct Node **p2=H; if(*p2==NULL) *p2=temp;
        *H=temp;//Don't put p here instead of *H, because *H is itself is pointing to a pointer, 
                //which is pointing to a struct node, whereas p is not.
    else
    {
        while(p && p->value<key)
        {
            q=p;
            p=p->next;
        }   

        if(p==*H)
        {
            temp->next=*H;//Value of particular block in hash table will be stored in temp->next;
            *H=temp;//temp will be stored in particular block of hash table.
        }
        else
        {
            temp->next=q->next;
            q->next=temp;
        }
    }
}

struct Node* search(struct Node* p,int key)
{
    while(p!=NULL)
    {
        if(key==p->value)
            return p;
        p=p->next;      
    }
    return NULL;
}
//Linked List code ends here.

int hash(int key)
{
    return key%10;
}

void insert(struct Node* H[],int key)
{
    int index=hash(key);
    sortedInsert(&H[index],key);//Pass particular block address.
}

int main()
{
    struct Node *HT[10],*temp;
    int i;

    for(i=0;i<10;i++)
        HT[i]=NULL;

    insert(HT,12);
    insert(HT,22);
    insert(HT,42);

    temp=search(HT[hash(22)],22);

    if(temp!=NULL)
        printf("%d",temp->value);
    else
        printf("Not found");
    return 0;
}