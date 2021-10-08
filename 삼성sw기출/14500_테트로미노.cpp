#include<iostream>
#include<algorithm>
using namespace std;
int n, m, map[500][500], visited[500][500];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
int max_val;
void dfs(int y, int x, int cnt, int val);
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 1;
			dfs(i, j, 1, map[i][j]);
			visited[i][j] = 0;
		}
	}
	cout << max_val << endl;
}
void dfs(int y, int x, int cnt, int val)
{
	if (cnt == 4) {
		max_val = max(max_val, val);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < n && nx < m&&!visited[ny][nx]) {
			visited[ny][nx] = 1;
			dfs(ny, nx, cnt + 1, val + map[ny][nx]);
			visited[ny][nx] = 0;
		}
	}
	// ㅏ,ㅓ,ㅗ,ㅜ 
	if (y - 1 >= 0 && y + 1 < n && x + 1 < m) {
		max_val = max(max_val, map[y][x] + map[y - 1][x] + map[y + 1][x] + map[y][x + 1]);
	}
	if (y - 1 >= 0 && y + 1 < n && x - 1 >= 0) {
		max_val = max(max_val, map[y][x] + map[y][x - 1] + map[y - 1][x] + map[y + 1][x]);
	}
	if (y - 1 >= 0 && x - 1 >= 0 && x + 1 < m) {
		max_val = max(max_val, map[y][x] + map[y-1][x] + map[y ][x-1] + map[y ][x+1]);
	}
	if (y +1 <n && x - 1 >= 0 && x + 1 < m) {
		max_val = max(max_val, map[y][x] + map[y + 1][x] + map[y][x - 1] + map[y][x + 1]);
	}
}
