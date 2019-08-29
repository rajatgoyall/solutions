#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>entry;
vector<pair<int,int>>exit1;
vector<int>cost;
int main()
{
int n;
cin>>n;

int x1,y1,x2,y2,d;

for(int i=0;i<n;i++)
{
cin>>x1>>y1>>x2>>y2>>d;
entry.push_back({x1,y1});
exit1.push_back({x2,y2});
cost.push_back(d);
}


int sx=-1,sy=-1,ex=-1,ey=-1;

cin>>sx>>sy>>ex>>ey;

entry.push_back({sx,sy});
entry.push_back({ex,ey});
exit1.push_back({sx,sy});
exit1.push_back({ex,ey});
cost.push_back(0);
cost.push_back(0);
int dis[n+2][n+2];
memset(dis,0,sizeof(dis));

for(int i=0;i<n+2;i++)
{
for(int j=0;j<n+2;j++)
{
if(i==j)
continue;

int d1=abs(exit1[i].first-entry[j].first)+abs(exit1[i].second-entry[j].second)+cost[i];
int d2=abs(exit1[i].first-exit1[j].first)+abs(exit1[i].second-exit1[j].second)+cost[i];
d1=min(d1,d2);
dis[i][j]=d;
}
}
for(int i=0;i<n+2;i++)
{

for(int j=0;j<n+2;j++)
{

cout<<dis[i][j]<<" ";

}
cout<<endl;
}

for(int k=0;k<n+2;k++)
{
for(int i=0;i<n+2;i++)
{
for(int j=0;j<n+2;j++)
{
if(dis[i][k]+dis[k][j]<dis[i][j])
{
dis[i][j]=dis[i][k]+dis[k][j];
}
}
}
}
for(int i=0;i<n+2;i++)
{

for(int j=0;j<n+2;j++)
{

cout<<dis[i][j]<<" ";

}
cout<<endl;
}



cout<<dis[n][n+1];




return 0;
}
