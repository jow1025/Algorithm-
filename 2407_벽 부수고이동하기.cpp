#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define endl '\n'
int visited[1000][1000][2];
int map[1000][1000];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m;
int ans;
void bfs(int y, int x, int cnt);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			map[i][j] = s[j] - '0';
		}
	}
	bfs(0, 0, 0);
	cout << ans << endl;
}
void bfs(int y, int x, int wall)
{
	visited[y][x][wall] = 1;
	//좌표,뿌셨는지 여부
	queue<pair<pair<int, int>, int>>q;
	q.push({ {y,x }, wall });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int wall = q.front().second;
		q.pop();
		if (y == n - 1 && x == m - 1) {
			ans = visited[y][x][wall];
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m) {

				//3가지 케이스
				/*
					1. 벽을 만났는 데 이미 벽을 뚫은 경우
					2. 벽을 만났는데 벽을 뚫은 적이 없을 때: 벽뚫
					3. 다음좌표가 벽이 아니고 그냥 돌아다닐 수 있을 때
					
					-> 1번은 continue랑 똑같음(무시)
				*/
				if (map[ny][nx] && wall == 0) {
					visited[ny][nx][wall + 1] = visited[y][x][wall] + 1;
					q.push({ {ny,nx},wall + 1 });
				}
				else if (!map[ny][nx] && !visited[ny][nx][wall]) {
					visited[ny][nx][wall] = visited[y][x][wall] + 1;
					q.push({ {ny,nx},wall });
				}
			}
		}
	}
	ans = -1;
}