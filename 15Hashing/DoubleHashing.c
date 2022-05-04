#include<stdio.h>
#include<stdlib.h>
#define PRIME 7
#define SIZE 10

int hash(int key)
{
    return key%SIZE;
}

int primeHash(int key)
{
    return PRIME - (key % PRIME);
}

int doubleHash(int H[],int key)
{
    int i=1;
    while(H[( hash(key) + i*primeHash(key) )% SIZE ]!=0)
        i++;

    return ( hash(key) + i*primeHash(key) )% SIZE;
}

void insert(int H[],int key)
{
    int index=hash(key);

    if(H[index]!=0)
        index=doubleHash(H,key);    
    H[index]=key;
}

int search(int H[],int key)
{
    int i=0;

    while( H[ ( hash(key) + i*primeHash(key) )% SIZE ] !=key &&
H[ ( hash(key) + i*primeHash(key) )% SIZE ]!=0 )
        i++;

    if((H[ ( hash(key) + i*primeHash(key) )% SIZE] )==key)
        return ( hash(key) + i*primeHash(key) )% SIZE;
    else    
        return -1;
}

int main()
{
    int i,HT[SIZE]={0},temp;

    insert(HT,12);
    insert(HT,25);
    insert(HT,35);
    insert(HT,26);

    printf("key found at index %d",search(HT,26));
    return 0;
}