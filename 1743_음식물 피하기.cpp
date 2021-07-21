#include<iostream>
#include<algorithm>
using namespace std;
int map[101][101];
int visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m, k, a, b, res,cnt;
void dfs(int y, int x);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j] && map[i][j] == 1)
			{
				dfs(i, j);
				res = max(res, cnt);
				cnt = 0;
			}
		}
	}
	cout << res << endl;
	return 0;
}
void dfs(int y, int x)
{
	cnt++;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 1 && nx >= 1 && ny <= n && nx <= m) {
			if (!visited[ny][nx]&&map[ny][nx])
				dfs(ny, nx);
		}
	}
}