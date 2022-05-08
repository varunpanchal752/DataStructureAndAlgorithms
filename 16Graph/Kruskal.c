#include<stdio.h>
#define I 32767

void Union(int u, int v, int s[]){
    if (s[u] < s[v]){
        s[u] += s[v];
        s[v] = u;
    } else {
        s[v] += s[u];
        s[u] = v;
    }
}
 
int Find(int u, int s[]){
    int x = u;
    int v = 0;
 
    while (s[x] > 0){
        x = s[x];
    }
 
    while (u != x){
        v = s[u];
        s[u] = x;
        u = v;
    }
    return x;
}

void kruskalsMST(int edges[][9])
{
    int included[9]={0},set[8]={-1},t[2][6];
    int i=0,j,k,n=7,e=9,min,u,v;

    while(i<n-1)
    {
        min=I;
        for(j=0;j<e;j++)
        {
            if(included[j]==0 && edges[2][j]<min)
            {
                min=edges[2][j];
                k=j;
                u=edges[0][j];v=edges[1][j];
            }
        }
        if(Find(u,set)!=Find(v,set))
        {
            t[0][i]=u;t[1][i]=v;
            Union(Find(u,set),Find(v,set),set);
            i++;
        }
        included[k]=1;
    }

    for(i=0;i<n-1;i++)
    {
        printf("( %d, %d )\n",t[0][i],t[1][i]);
    }
}

int main()
{
    int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
 
    kruskalsMST(edges);
    return 0;
}