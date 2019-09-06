#include<iostream>
#define QS 2000000

using namespace std;

class Point
{
	public:
		int x;
		int y;
};

int matrix[100][100], visited[100][100], dis[100][100];
int n;
Point src,dest;
Point movement[4]={{-1,0},{1,0},{0,-1},{0,1}};
Point queue[QS];
int front=0,rear=0;

bool isSafe(Point p)
{
	if(p.x>=0 && p.y>=0 && p.x<n && p.y<n)
		return true;
	return false;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>matrix[i][j];
			visited[i][j]=0;
			dis[i][j]=0;
		}
	}
	
	cin>>src.x>>src.y>>dest.x>>dest.y;
	
	queue[(rear++)%QS]=src;
	visited[src.x][src.y]=1;
	dis[src.x][src.y]=0;
	while(front!=rear)
	{
		Point u = queue[(front++)%QS];
		for(int i=0;i<4;i++)
		{
			Point v;
			v.x=u.x+movement[i].x;
			v.y=u.y+movement[i].y;
			if(isSafe(v) && matrix[v.x][v.y]==1 && visited[v.x][v.y]==0)
			{
				if(i==0 || i==1)
					dis[v.x][v.y]=dis[u.x][u.y];
				if(i==2 || i==3)
					dis[v.x][v.y]=1+dis[u.x][u.y];
				visited[v.x][v.y]=1;
				queue[(rear++)%QS]=v;
			}
		}
	}
	cout<<dis[dest.x][dest.y];
}
/*
5
0 1 1 0 1
1 0 0 1 0
1 0 0 0 1
0 1 0 1 1
1 0 1 1 1
2 4 4 2
*/
