#include<iostream>

using namespace std;
int n,e;
int graph[100][100];
int color[100]; //0 White 1 Gray 2 Black

bool Cyclic(int u)
{
    color[u]=1;
    for(int i=0;i<n;i++)
    {
        if(graph[u][i])
        {
            if(color[i]==1)
                return true;
            if(color[i]==0 && Cyclic(i))
                return true;
        }
    }
    color[u]=2;
    return false;
}

bool isCyclic()
{
    for(int i=0;i<n;i++)
    {
        if(color[i]==0)
        {
            if(Cyclic(i))
                return true;
        }
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>e;
        for(int i=0;i<n;i++)
        {
            color[i]=0;
        }
        for(int i=0;i<e;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x-1][y-1]=1;
        }
        cout<<isCyclic();
    }
}
