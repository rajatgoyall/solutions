#include<iostream>
#define INT_MAX 2000000000

using namespace std;

int n;
int ans;

int abs(int x)
{
   if(x<0)
        return -x;
    return x;
}

class Point
{
public:
    int x;
    int y;
};
int distanceB(Point p1,Point p2)
    {
        return (abs(p1.x-p2.x)+abs(p1.y-p2.y));
    }

Point A[12];
int dis[12][12];
bool visited[12];

void permute(int src, int cost, int level)
{
    if(level==n)
    {
        if(ans>cost+dis[src][n+1])
        {
            ans=cost+dis[src][n+1];
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false && src!=i && ans>cost+dis[src][i])
        {
            visited[i]=true;
            cout<<cost+dis[src][i]<<" ";
            permute(i,cost+dis[src][i],level+1);
            visited[i]=false;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int test_case=1;test_case<=t;test_case++)
    {
        ans=INT_MAX;
        cin>>n;
        cin>>A[0].x>>A[0].y;
        cin>>A[n+1].x>>A[n+1].y;
        for(int i=1;i<=n;i++)
        {
            cin>>A[i].x>>A[i].y;
            visited[i]=false;
        }
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+2;j++)
            {
                if(i==j)
                    dis[i][j]=0;
                dis[i][j]=distanceB(A[i],A[j]);
                dis[j][i]=distanceB(A[i],A[j]);
            }
        }
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }

        permute(0,0,0);
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
}
/*
1
5
0 0
100 100
70 40
30 10
10 5
90 70
50 20
6
88 81
85 80
19 22
31 15
27 29
30 10
20 26
5 14
*/
