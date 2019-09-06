#include<iostream>

using namespace std;

int n;
int A[12][12];
int temp[12][12];
int mx=-1;

void dfs(int x, int y, int coins)
{
    if(A[x][y]==1 || A[x][y]==3)
        return;
    int r = A[x][y];
    if(A[x][y]==2)
        coins++;
    A[x][y]=3;

    if(x==n-1 && y==n-1)
    {
        if(mx<coins)
        {
            mx=coins;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    temp[i][j]=A[i][j];
                }
            }   
        }
    }

    if(x-1>=0)dfs(x-1,y,coins);
    if(y-1>=0)dfs(x,y-1,coins);
    if(x+1<n)dfs(x+1,y,coins);
    if(y+1<n)dfs(x,y+1,coins);

    A[x][y]=r;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
    dfs(0,0,0);
    cout<<mx<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
}