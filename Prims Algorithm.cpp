#include<iostream>
using namespace std;
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},m,mincost=0,cost[10][10];
int main()
{
    cout<<"Enter number of nodes:";
    cin>>n;
    cout<<"Enter the adjacency matrix:\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>cost[i][j];
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    visited[1]=1;
    cout<<endl;
    while(ne<n)
    {
        for(i=1,m=999;i<=n;i++)
        for(j=1;j<=n;j++)
        if(cost[i][j]<m)
        if(visited[i]!=0)
        {
            m=cost[i][j];
            a=u=i;
            b=v=j;
        }
        if(visited[u]==0 || visited[v]==0)
        {
            cout<<"Egde"<<ne++<<":("<<a<<","<<b<<") cost:"<<m<<endl;
            mincost+=m;
            visited[b]=1;
        }

        cost[a][b]=cost[b][a]=999;
    }
    cout<<"Minimum cost is:"<<mincost;
}
