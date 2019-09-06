#include <iostream>
using namespace std;

solve(int a[], int vis[], int p1, int p2, int n, int &ans){
    if(p1 == p2){

        if(p1 > ans){
            ans = p1;
        }
    }


    for(int i=0 ; i<n ; ++i){

        if(vis[i] == 0){
            vis[i] = 1;
            solve(a, vis, p1 + a[i], p2, n, ans);
            solve(a, vis, p1, p2 + a[i], n, ans);
            vis[i] = 0;
        }
    }
}
main(){

    int n;
    cin>>n;
    int a[n];

    for(int i=0 ; i<n ; ++i){
        cin>>a[i];
    }

    int vis[n] = {0};
    int ans = -1;
    solve(a,vis,0,0,n,ans);

    cout<<ans;
}
