#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

int findMax(int A[],int n)
{
    int i,max=-32456;
    for(i=0;i<n;i++)
    {
        if(max<A[i])
            max=A[i];
    }
    return max;
}

void radixSort(int A[],int n)
{
    int i,j,max;
    struct Node** bins;
    bins = (struct Node**)malloc(10*sizeof(struct Node*));

    for(i=0;i<10;i++)
        bins[i]=NULL;

    max=findMax(A,n);
    int k=1;
    while(max>0)
    {
        for(i=0;i<n;i++)
        {
            struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
            temp->value=A[i];
            temp->next=NULL;

            if(bins[(A[i]/k)%10]==NULL)
            {
                bins[(A[i]/k)%10]=temp;
            }    
            else
            {
                //Don't change directly on bin pointer value, instead do any change using temporary pointer p.
                struct Node *p=bins[(A[i]/k)%10];
                while( p->next!=NULL )
                {    
                    p = p->next;
                }
                p->next=temp;
            }
        }
        k*=10;
        
        i=0;j=0;
        while(j<10)
        {
            if(bins[j]!=NULL)
            {
                A[i++]=bins[j]->value;
                struct Node* p=bins[j];
                bins[j]=bins[j]->next;
                free(p);
            }   
            else
                ++j;
        }

        max/=10;
    }

    free(bins);
}

int main()
{
    int A[]={237, 146, 259, 348, 152, 163, 235, 48, 36, 62},n=10,i;
 
    radixSort(A,n);
 
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}