#include<iostream>
using namespace std;

struct Node{
	bool left;
	bool right;
	bool up;
	bool bottom;
};

struct Point{
	int x;
	int y;
};

Node a[1000][1000];
int arr[1000][1000];
int dis[1000][1000];
int vis[1000][1000];
Point queue[1000000];
int sx, sy, d;
int n, m;
int ans;

bool isvalid(int p, int q){
	return p >= 0 && q >= 0 && p < n && q < m;
}


void bfs(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			vis[i][j] = 0;
			dis[i][j] = 0;
		}
	}
	int front = 0;
	int rear = 0;
	dis[sx][sy] = 1;
	vis[sx][sy] = 1;
	if (arr[sx][sy] == 0){
		ans = 0;
		return;
	}
	queue[rear].x = sx;
	queue[rear].y = sy;
	rear = (rear + 1) % 1000000;
	while (front != rear){
		int p = queue[front].x;
		int q = queue[front].y;
		front = (front + 1) % 1000000;
		if (1 + dis[p][q] <= d){
			if (isvalid(p - 1, q) && vis[p - 1][q] == 0 && a[p - 1][q].bottom && a[p][q].up){
				vis[p - 1][q] = 1;
				dis[p - 1][q] = 1 + dis[p][q];
				ans++;
				queue[rear].x = p - 1;
				queue[rear].y = q;
				rear = (rear + 1) % 1000000;
			}

			if (isvalid(p + 1, q) && vis[p + 1][q] == 0 && a[p + 1][q].up && a[p][q].bottom){
				vis[p + 1][q] = 1;
				dis[p + 1][q] = 1 + dis[p][q];
				ans++;
				queue[rear].x = p + 1;
				queue[rear].y = q;
				rear = (rear + 1) % 1000000;
			}

			if (isvalid(p, q-1) && vis[p][q-1] == 0 && a[p][q-1].right && a[p][q].left){
				vis[p][q-1] = 1;
				dis[p][q-1] = 1 + dis[p][q];
				ans++;
				queue[rear].x = p;
				queue[rear].y = q-1;
				rear = (rear + 1) % 1000000;
			}

			if (isvalid(p, q+1) && vis[p][q+1] == 0 && a[p][q+1].left && a[p][q].right){
				vis[p][q+1] = 1;
				dis[p][q+1] = 1 + dis[p][q];
				ans++;
				queue[rear].x = p;
				queue[rear].y = q+1;
				rear = (rear + 1) % 1000000;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while (t--){
	cin >> n >> m >> sx >> sy >> d;
	ans = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 1){
				a[i][j].left = true ;
				a[i][j].right = true;
				a[i][j].up = true;
				a[i][j].bottom = true;

			}
			else if (arr[i][j] == 2){
				a[i][j].left = false;
				a[i][j].right = false;
				a[i][j].up = true;
				a[i][j].bottom = true;
			}
			else if (arr[i][j] == 3){
				a[i][j].left = true;
				a[i][j].right = true;
				a[i][j].up = false;
				a[i][j].bottom = false;
			}
			else if (arr[i][j] == 4){
				a[i][j].left = false;
				a[i][j].right = true;
				a[i][j].up = true;
				a[i][j].bottom = false;
			}
			else if (arr[i][j] == 5){
				a[i][j].left = false;
				a[i][j].right = true;
				a[i][j].up = false;
				a[i][j].bottom = true;
			}
			else if (arr[i][j] == 6){
				a[i][j].left = true;
				a[i][j].right = false;
				a[i][j].up = false;
				a[i][j].bottom = true;
			}
			else if (arr[i][j] == 7){
				a[i][j].left = true;
				a[i][j].right = false;
				a[i][j].up = true;
				a[i][j].bottom = false;
			}
			else{
				a[i][j].left = false;
				a[i][j].right = false;
				a[i][j].up = false;
				a[i][j].bottom = false;
			}
		}
	}
	bfs();
	cout << ans << endl;
	}
	return 0;
}