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

void binSort(int A[],int n)
{
    int max,i,j=0;
    struct Node** bins;
    max=findMax(A,n);
    bins = (struct Node**)malloc((max+1)*sizeof(struct Node*));

    for(i=0;i<max+1;i++)
        bins[i]=NULL;

    for(i=0;i<n;i++)
    {
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        temp->value=A[i];
        temp->next=NULL;
        if(bins[A[i]]==NULL)
            bins[A[i]]=temp;
        else
        {
            while(bins[A[i]]->next!=NULL)
                bins[A[i]]=bins[A[i]]->next;
            
            bins[A[i]]->next=temp;
        }
    }    

    i=0;
    while(j<max+1)
    {
        if(bins[j]!=NULL)
        {
            A[i++]=bins[j]->value;
            struct Node* p=bins[j];
            bins[j]=bins[j]->next;
            free(p);
        }   
        else
            j++;
    }
    free(bins);
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
 
    binSort(A,n);
 
    for(i=0;i<10;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}