#include<iostream>
using namespace std;

int arr[100][100];
int vis[100];
int n, e;
//int time;
int max_prob = 0;
int ans;
//int current_prob;

void solve(int src, int current_time, int current_prob){
	if (src >= n)
		return;
	if (current_time < 10){
		if (max_prob < current_prob){
			max_prob = current_prob;
			ans = src;
		}
		return;
	}
	for (int i = 0; i < n; i++){
		if (vis[i] == 0 && arr[src][i] != 0){
			vis[i] = 1;
			solve(i, current_time - 10, current_prob*arr[src][i]);
			vis[i] = 0;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int time;
		cin >> n >> e;
		cin >> time;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				arr[i][j] = 0;
			}
		}
		for (int j = 0; j < e; j++){
			int x, y, z;
			cin >> x >> y >> z;
			arr[x][y] = z;
		}
		for (int i = 0; i < n; i++){
			vis[i] = 0;
		}
		vis[0] = 1;
		ans = 0;
		solve(0, time, 1);
		cout << ans << endl;
	}


	return 0;
}