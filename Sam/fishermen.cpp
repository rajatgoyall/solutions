#include<iostream>
using namespace std;

int dp[100][100];
int vis[100];
int g[4];
int val[4];
int n;
int ans;

int abst(int x, int y){
	if (x > y)
		return x - y;
	else
		return y - x;
}

int findmin(int x){
	int ret = 0;
	for (int p = 0; p < val[x]; p++){
		int indx = 0;
		int mini = 1e5;
		for (int i = 1; i <= n; i++){
			if (vis[i] == 0){
				if (dp[x][i] <= mini){
					mini = dp[x][i];
					indx = i;
				}
			}
		}
		vis[indx] = 1;
		ret += mini;
	}
	return ret;
}


int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		cin >> g[1] >> val[1] >> g[2] >> val[2] >> g[3] >> val[3];
		for (int i = 1; i <= n; i++){
			dp[1][i] = abst(g[1], i) + 1;
			dp[2][i] = abst(g[2], i) + 1;
			dp[3][i] = abst(g[3], i) + 1;
		}
		for (int i = 1; i <= n; i++){
			vis[i] = 0;
		}
		ans = 1e7;
		for (int i = 1; i <= 3; i++){
			for (int j = 1; j <= 3; j++){
				if (i != j){
					int s = 0;
					for (int k = 1; k <= 3; k++){
						if (j != k && k != i){
							for (int i = 1; i <= n; i++){
								vis[i] = 0;
							}
							s += findmin(i);
							s += findmin(j);
							s += findmin(k);
							if (s < ans)
								ans = s;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}