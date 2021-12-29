#include<stdio.h>
#include<stdlib.h>

struct Node{
    int col;
    int data;
    struct Node *next;
};

struct Node** Create(int A[][6],int m,int n){
    int i,j;
    struct Node **Head=(struct Node **)malloc(m*sizeof(struct Node*)), *last,*t;
    
    for(i=0;i<m;i++){
        Head[i]=NULL;
       
        for(j=0;j<n;j++){
            if(A[i][j]!=0){
                t=(struct Node *)malloc(sizeof(struct Node));
                t->data=A[i][j];
                t->col=j; 
                t->next=NULL;
                if(Head[i]==NULL){
                    last=Head[i]=t;
                }
                else{
                    last->next=t;
                    last=t;
                }   
            }
        }
    }

    return Head;
}

void Display(struct Node **p,int m,int n){
    int i,j;
    struct Node *pc=NULL;
    
    for(i=0;i<m;i++){
        pc = p[i];
    
        if(pc!=NULL){
            for(j=0;j<n;j++){
                if(pc!=NULL && pc->col==j){
                    printf("%d ",pc->data);
                    pc=pc->next;
                }
                else{
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }printf("\n");
}

struct Node** Add(struct Node **p,struct Node **q,int m,int n){
    int i,j;
    struct Node *pc=NULL,*pc2=NULL,**r=(struct Node**)malloc(m*sizeof(struct Node *)), *pc3=NULL, *t;
    for(i=0;i<m;i++){
        r[i]=NULL;
        pc = p[i];
        pc2= q[i];
        pc3=r[i];
        for(j=0;j<n;j++){
            if(pc!=NULL && pc2!=NULL ){
                t=(struct Node *)malloc(sizeof(struct Node));
                t->next=NULL;
                if(pc->col < pc2->col){
                    t->data=pc->data;
                    t->col=pc->col;                            
                    pc=pc->next;
                }
                else if(pc2->col < pc->col){
                    t->data=pc2->data;
                    t->col=pc2->col;
                    pc2=pc2->next;
                }
                else if(pc->col == pc2->col){
                    t->data=pc->data + pc2->data;
                    t->col=pc->col;
                    pc=pc->next; 
                    pc2=pc2->next;
                }
                if(pc3==NULL){
                    pc3=r[i]=t;
                }
                else if(pc3!=NULL){
                    pc3->next=t;
                    pc3=t;
                }
            }
        }
        while(pc!=NULL){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=pc->data;
            t->col=pc->col;
            t->next=NULL;                            
            pc=pc->next;
            if(pc3==NULL){
                pc3=r[i]=t;
            }
            else if(pc3!=NULL){
                pc3->next=t;
                pc3=t;
            }                   
        }
        while(pc2!=NULL){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=pc2->data;
            t->col=pc2->col;                            
            t->next=NULL;                            
            pc2=pc2->next;
            if(pc3==NULL){
                pc3=r[i]=t;
            }
            else if(pc3!=NULL){
                pc3->next=t;
                pc3=t;
            }
        }
    }
    return r;
}

int main(){
    int A[5][6]={
        {0,0,0,9,0,1},
        {4,3,1,0,0,1},
        {1,5,0,0,0,6},
        {0,0,0,0,0,0},
        {8,2,0,0,0,7},
        }, m=5, n=6, B[5][6]={
                        {0,1,0,1,4,0},
                        {7,0,1,0,2,0},
                        {0,1,4,8,0,0},
                        {3,0,1,0,0,0},
                        {2,0,0,8,7,0},
                    };
    
    struct Node **first,**second,**third=NULL;
    first=Create(A,m,n);
    second=Create(B,m,n);
    
    third=Add(first,second,m,n);
    Display(third,m,n);
    
    return 0;
}