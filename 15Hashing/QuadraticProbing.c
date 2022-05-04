#include<stdio.h>
#include<stdlib.h>


int hash(int key)
{
    return key%10;
}

int probe(int H[],int key)
{
    int index=hash(key);
    int i=0;
    while(H[(index + i*i)%10]!=0)
        i++;
    return (index + i*i)%10;
}

void insert(int H[],int key)
{
    int index=hash(key);

    if(H[index]!=0)
        index=probe(H,key);    
    H[index]=key;
}

int search(int H[],int key)
{
    int index=hash(key),i=0;

    while( H[(index + i*i)%10]!=key && H[(index + i*i)%10]!=0 )
        i++;
    if((H[(index + i*i)%10])==key)
        return (index + i*i)%10;
    else    
        return -1;
}

int main()
{
    int i,HT[10]={0},temp;

    insert(HT,12);
    insert(HT,25);
    insert(HT,35);
    insert(HT,26);

    printf("key found at index %d",search(HT,26));
    return 0;
}