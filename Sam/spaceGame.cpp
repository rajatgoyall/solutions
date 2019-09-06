#include<iostream>

using namespace std;

int n;
int ans;
int A[12][5];
int tempA[12][5];

int func(int row, int col,int coins)
{
    if(row<0 || col<0 || col> 5)
        return coins;
    if(tempA[row][col]==2)
        return coins;
    if(tempA[row][col]==1)
        coins++;
    ans=max(ans,func(row-1,col-1,coins));
    ans=max(ans,func(row-1,col,coins));
    ans=max(ans,func(row-1,col+1,coins));

}

int main()
{
    int t;
    cin>>t;
    for(int test_case=1;test_case<=t;t++)
    {
        cin>>n;
        ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
                cin>>A[i][j];
            }
        }
        A[n][0]=-1;
        A[n][1]=-1;
        A[n][2]=0;
        A[n][3]=-1;
        A[n][4]=-1;

        for(int i=0;i<=(n-5);i++) //Loop will run n-4 times, bursting enemies in different set of 5 rows in each loop.
        {
            for(int p=0;i<n;p++)    //Copy to temparray.
            {
                for(int j=0;j<5;j++)
                {
                    tempA[p][j]=A[p][j];
                }
            }
            for(int count=0;count<5;count++)
            {
                for(int j=0;j<5;j++)
                {
                    if(tempA[i+count][j]==2)
                        tempA[i+count][j]=0;
                }
            }
            ans = max(ans,func(n,2,0));
        }

        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
}
/*
1
6
0 1 0 2 0
0 2 2 2 1
0 2 1 1 1
1 0 1 0 0
0 0 1 2 2
1 1 0 0 1
*/
