#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define endl '\n'
int map[9][9], temp[9][9];
int n, m, max_val;
int visited[9][9];
vector<pair<int, int>>v;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void wall(int cnt);
void bfs();
void copy_map();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				v.push_back({ i,j });
		}
	}
	wall(0);
	cout << max_val << endl;
	return 0;
}
void wall(int cnt)
{
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				wall(cnt + 1);
				map[i][j] = 0;
				
			}
		}
	}
}
void bfs()
{
	copy_map();
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>>q;
	
	for (int i = 0; i < v.size(); i++) {
		q.push({v[i].first,v[i].second});
		visited[v[i].first][v[i].second] = 1;
	}
	
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 1 && nx >= 1 && nx <= m && ny <= n && !visited[ny][nx]&&!temp[ny][nx]) {
				temp[ny][nx] = 2;
				q.push({ ny,nx });
				visited[ny][nx] = 1;
			}
		}
	}
	
	int num = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (temp[i][j] == 0)
				num++;
		}
	}
	max_val = max(max_val, num);
}
void copy_map()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp[i][j]= map[i][j];
		}
	}
}