#include<iostream>
#include<queue>
using namespace std;
int n, m;
char map[101][101];
int visited[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void bfs(int y, int x);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	bfs(0, 0);
	

	cout << visited[n-1][m-1] << endl;
	return 0;
}
void bfs(int y, int x)
{
	queue<pair<int, int>>q;
	q.push({ y,x });
	visited[y][x] = 1;
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
				if(map[ny][nx]=='1'&&!visited[ny][nx]){
					q.push({ ny,nx });
					visited[ny][nx] = visited[y][x] + 1;
				}
			}
		}

	}
}