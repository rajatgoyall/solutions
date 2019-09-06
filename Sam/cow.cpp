#include<iostream>
#define INT_MAX 1000000000

using namespace std;
int A[20];
int data[20];
int dataA[20];
int visited[20];
int n,c;
int maxi;
int gLevel;

void combination(int start, int end, int level)
{
	if(level==c)
	{
		int mini=INT_MAX;
		for(int i=0;i<level-1;i++)
		{
			if(data[i+1]-data[i]<mini)
				mini=data[i+1]-data[i];
		}
		if(mini>maxi)
		{
			maxi=mini;
			gLevel=level;
			for(int i=0;i<level;i++)
			{
				dataA[i]=data[i];
			}
		}
	}

	for(int i=start;i<end;i++)
	{
		if(visited[i]==0)
		{
			data[level]=A[i];
			visited[i]=1;
			combination(start+1,end,level+1);
			visited[i]=0;
		}
	}
}

int main()
{
	maxi=-1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		visited[i]=0;
	}
	cin>>c;
	combination(0,n,0);
	cout<<maxi;
	for(int i=0;i<gLevel;i++)
	{
		cout<<dataA[i]<<" ";
	}
}