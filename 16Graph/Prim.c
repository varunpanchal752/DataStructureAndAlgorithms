#include<stdio.h>
#define I 32767

void primsMST(int cost[][8],int n)
{
    int i,j,k,min=I,u,v,t[2][n-1],near[n+1];

    for(i=0;i<n+1;i++)
        near[i]=I;

    for(i=1;i<n+1;i++)//n+1, as cost matrix size is (n+1)*(n+1).
    {
        for(j=i;j<n+1;j++)
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                u=i;v=j;
            }
        }
    }

    t[0][0]=u;t[1][0]=v;
    near[u]=near[v]=0;

    for(i=1;i<n+1;i++)
    {
        if(near[i]!=0)
        {
            if(cost[i][u]<cost[i][v])
                near[i]=u;
            else
                near[i]=v;
        }
    }

    for(i=1;i<n-1;i++)
    {
        min=I;
        for(j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][near[j]]<min)
            {
                min=cost[j][near[j]];
                k=j;
            }
        }

        t[0][i]=k;t[1][i]=near[k];
        near[k]=0;

        for(j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][k]<cost[j][near[j]])
                near[j]=k;
        }
    }    

    for(i=0;i<n-1;i++)
    {
        printf("( %d,%d )\n",t[0][i],t[1][i]);
    }
}


int main()
{
    int cost [8][8]={
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
 
    int n = 7;//no of vertices
 
    primsMST(cost, n);
    return 0;
}