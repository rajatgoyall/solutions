#include<iostream>
#define QS 2500

using namespace std;

int graph[50][50];
int color[50];
int n;
int queue[QS];
int front=0,rear=0;

bool bfs(int src)
{
	color[src]=1;
	queue[(rear++)%QS]=src;
	while(front!=rear)
	{
		src = queue[(front++)%QS];
		if(graph[src][src])
			return false;
		for(int i=0;i<n;i++)
		{
			if(graph[src][i])
			{
				if(color[i]==-1)
				{
					color[i]=1-color[src];
					queue[(rear++)%QS]=i;
				}
				else if (color[src]==color[i])
				{
					return false;
				}
			}
		}
		return true;
	}
}


int main()
{
	cin>>n;
	bool ans=true;
	for(int i=0;i<n;i++)
	{
		color[i]=-1;
		for(int j=0;j<n;j++)
		{
			cin>>graph[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(color[i]==-1)
			ans = ans && bfs(i);
	}
	if(ans)
	{
		for(int i=0;i<n;i++)
		{
			if(color[i]==1)
				cout<<i+1<<" ";
		}
	}
	else
		cout<<-1;
}