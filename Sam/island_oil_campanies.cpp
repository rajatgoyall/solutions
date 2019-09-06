/*Code Created By ShiviChan(Shivam Chandra)
All right for the code is reserved with ShiviChan*/

#include<bits/stdc++.h>
using namespace std;
int arr[10000];
int main()
{
    int t;
    cin>>t;
   while(t--)
    {
        int n,k;
        cin>>k>>n;
        int sum=0;

        for(int i=0;i<n;i++)
            {
                cin>>arr[i];
                sum+=arr[i];
                arr[i+n]=arr[i];
            }

        sum+=100;
        int sum3=0;
        int x3=-1;
        for(int x=0;x<n;x++)
            {
                int l=0,r=sum;
                int ans=-1;

                while(l<=r)
                    {
                        int mid=(l+r)/2;
                        int s1=0,f=0,cnt=0;
                        s1=arr[x];
                        for(int i=x+1;i<x+n;i++)
                            {
                                if(s1>=mid)
                                    {
                                        cnt++;
                                        s1=0;
                                    }
                                    s1+=arr[i];
                            }
                if(s1>=mid)
                    cnt++;


                if(cnt<k)
                    {
                        r=mid-1;
                    }
                else if (cnt==k)
                    {
                        ans=mid;
                        l=mid+1;
                    }
                else
                    {
                        l=mid+1;
                    }
                }

        if(ans>sum3)
            {
                sum3=ans;
                x3=x;
            }
    }

    int sz=arr[x3];
    int mn=INT_MAX,mx=INT_MIN;
     for(int i=x3+1;i<x3+n;i++)
     {
         if(sz>=sum3)
         {
            mn=min(mn,sz);
            mx=max(mx,sz);
             sz=0;
         }
         sz+=arr[i];
     }
        mn=min(mn,sz);
        mx=max(mx,sz);
    cout<<mx-mn<<endl;
    }
}
