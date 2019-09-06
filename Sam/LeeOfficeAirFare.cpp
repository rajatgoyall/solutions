#include<iostream>
#define INT_MAX 2000000000
using namespace std;

int n;
int A[12][12];
int ans=INT_MAX;
int visited[12];

void permute(int src, int cost, int level)
{
    if(level==n-1)
    {
        if(ans>cost+A[src][0])
            ans=cost+A[src][0];
        cout<<endl;
        return;
    }
    for(int i=1;i<n;i++)
    {
        if(visited[i]==false && A[src][i]!=0 && ans > cost + A[src][i])
        {
            visited[i]=true;
            cout<<cost+A[src][i]<<" ";
            permute(i,cost+A[src][i],level+1);
            visited[i]=false;
            //cost=cost-A[src][i];
        }
    }
}

int main()
{
    int test_case,t;
    cin>>t;
    for(test_case=1;test_case<t;t++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>A[i][j];
            }
            visited[i]=false;
        }
        visited[0]=true;
        permute(0,0,0);
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
}
