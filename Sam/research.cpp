#include<iostream>
using namespace std;
#define INT_MAX 1000000
int n,c;
int rare[10][2];
int area[10][10],vis[10][10],dis[10][10][10];
int max(int a,int b)
{
	return (a>b)?a:b;
}

int min(int a,int b)
{
	return (a>b)?b:a;
}

void bfs(int k,int i,int j,int d)
{
	if(k > c || i <0 || i>= n || j <0 || j>= n)
		return ;
	if(vis[i][j] && dis[i][j][k] < d)
		return;
	if(area[i][j] == 0)
		return;
	vis[i][j]=1;
	dis[i][j][k]=d;
	bfs(k, i+1,j,d+1);
	bfs(k, i-1,j,d+1);
	bfs(k, i,j+1,d+1);
	bfs(k, i,j-1,d+1);
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		//int n,c;
		cin >> n >> c;
		
		for(int i=0;i<c;i++){
			cin >> rare[i][0] >> rare[i][1];
			rare[i][0]--;rare[i][1]--;
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> area[i][j];
				vis[i][j]=0;
				for(int k=0;k<c;k++)
					dis[i][j][k]=-1;
			}
		}
		for(int i=0;i<c;i++)
		{
			bfs(i,rare[i][0],rare[i][1],0);
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
					vis[j][k]=0;
			}
		}
		int ans=INT_MAX,fl=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(area[i][j] == 1)
				{
					int mx=0;
					for(int k=0;k<c;k++)
					{
						if(dis[i][j][k] == -1)
							fl=1;
						mx=max(mx,dis[i][j][k]);
					}
					ans=min(ans,mx);	
				}
				
			}
		}

		if( fl==1)
			cout << "No answer\n" << endl;
		else
			cout << ans << endl;

	}
	return 0;
}