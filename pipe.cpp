#include <bits/stdc++.h> 
using namespace std; 
#define Max 1000 
#define row_size 3 
#define col_size 4 

int x = 1, y = 0; // starting index(x, y), 
int l = 4; // length of probe tool 

// input matrix containing the pipes 
int mt[row_size][col_size] = { { 0, 0, 4, 0 }, 
							{ 1, 3, 6, 0 }, 
							{ 5, 0, 0, 0 } }; 

// visited matrix checks for cells already visited 
int vi[row_size][col_size]; 

// calculates the depth of connection for each cell 
int depth[row_size][col_size]; 

int f = 0; 
int r = 0; 

// queue for BFS 
struct node { 
	int x; 
	int y; 
	int d; 
}; 
node q[Max]; 
void push(int a, int b, int d) // push function 
{ 
	node temp; 
	temp.x = a; 
	temp.y = b; 
	temp.d = d; 
	q[r++] = temp; 
	vi[a][b] = 1; 
} 
node pop() // pop function 
{ 
	node temp; 
	temp.x = q[f].x; 
	temp.y = q[f].y; 
	temp.d = q[f].d; 
	f++; 
	return temp; 
} 

// It can be simplified by converting the 7 
// values into direction based data. For e.g. 
// each value can be transformed into a structure 
// with 4 Boolean variables, one for each direction. 
// Alternatively, each number can be mapped to a 4 
// bit number where each bit represents a direction. 
bool s1(int i, int j) // conversion to final direction 
{ 
	if (i >= 0 && i < row_size && j >= 0 && 
		j < col_size && vi[i][j] == 0 && (mt[i][j] == 1 || 
		mt[i][j] == 3 || mt[i][j] == 6 || mt[i][j] == 7)) 
		return true; 
	else
		return false; 
} 

bool s2(int i, int j) // conversion to final direction 
{ 
	if (i >= 0 && i < row_size && j >= 0 && j < col_size && 
		vi[i][j] == 0 && (mt[i][j] == 1 || mt[i][j] == 2 || 
		mt[i][j] == 4 || mt[i][j] == 7)) 
		return true; 
	else
		return false; 
} 
bool s3(int i, int j) // conversion to final direction 
{ 
	if (i >= 0 && i < row_size && j >= 0 && j < col_size && 
		vi[i][j] == 0 && (mt[i][j] == 1 || mt[i][j] == 3 || 
		mt[i][j] == 4 || mt[i][j] == 5)) 
		return true; 
	else
		return false; 
} 
bool s4(int i, int j) // conversion to final direction 
{ 
	if (i >= 0 && i < row_size && j >= 0 && j < col_size && 
	vi[i][j] == 0 && (mt[i][j] == 1 || mt[i][j] == 2 || 
	mt[i][j] == 6 || mt[i][j] == 5)) 
		return true; 
	else
		return false; 
} 

// search for connection 
// We start by pushing the start node (X, Y) into a queue 
// with depth 1 and then start processing the queue till 
// it is empty. 
void bfs(int x, int y, int d) 
{ 
	push(x, y, d); 
	while (r > f) { 
		node temp = pop(); 
		int i = temp.x; 
		int j = temp.y; 
		int c = temp.d; 
		depth[i][j] = c; 

		if (mt[i][j] == 1 || mt[i][j] == 3 || 
			mt[i][j] == 4 || mt[i][j] == 5) { 
			if (s1(i, j + 1)) 
				push(i, j + 1, c + 1); 
		} 
		if (mt[i][j] == 1 || mt[i][j] == 2 || 
			mt[i][j] == 6 || mt[i][j] == 5) { 
			if (s2(i + 1, j)) 
				push(i + 1, j, c + 1); 
		} 
		if (mt[i][j] == 1 || mt[i][j] == 3 || 
			mt[i][j] == 7 || mt[i][j] == 6) { 
			if (s3(i, j - 1)) 
				push(i, j - 1, c + 1); 
		} 
		if (mt[i][j] == 1 || mt[i][j] == 2 || 
			mt[i][j] == 4 || mt[i][j] == 7) { 
			if (s4(i - 1, j)) 
				push(i - 1, j, c + 1); 
		} 
	} 
} 
int main() // main function 
{ 

	f = 0; 
	r = 0; 
	// matrix 
	for (int i = 0; i < row_size; i++) { 
		for (int j = 0; j < col_size; j++) { 

			// visited matrix for BFS set to 
			// unvisited for every cell 
			vi[i][j] = 0; 

			// depth set to max intial value 
			depth[i][j] = Max; 
		} 
	} 

	if (mt[x][y] != 0) // condition for BFS 
		bfs(x, y, 1); 

	int nc = 0; 
	for (int i = 0; i < row_size; i++) { 
		for (int j = 0; j < col_size; j++) { 
			if (depth[i][j] <= l) { 
				cout << "(" << i << ", " << j << ")"; 
				nc++; 
			} 
		} 
	} 
	cout << " " << nc << "\n"; 
} 
