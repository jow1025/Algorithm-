#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define endl '\n'
#define MAX 50
int t, n, m, r, c, l, map[MAX][MAX], visited[MAX][MAX];
int res;
int dx[4] = { -1,1,0,0, };
int dy[4] = { 0,0,-1,1 };
//좌,우, 상,하
void bfs(int y, int x);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;

	for (int cnt = 1; cnt <= t; cnt++) {
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		cin >> n >> m >> r >> c >> l;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}
		bfs(r, c);
		cout << "#" << cnt << " " << res << endl;
	}

	return 0;
}
void bfs(int y, int x)
{
	queue<pair<pair<int, int>, int>>q;
	res = 0;
	visited[y][x] = 1;
	q.push({ {y,x},1 });
	while (!q.empty()) {
		int pos_y = q.front().first.first;
		int pos_x = q.front().first.second;
		int val_time = q.front().second;
		q.pop();
		if (val_time > l)
			return;
		res++;
		int tmp = map[pos_y][pos_x];
		for (int i = 0; i < 4; i++) {
			//좌,우,상,하 방향에 대해 현재위치에서 연결할수있는지?

			//현재좌표에서 상하 좌우 터널로 갈수있는 곳만 연산
			if (i == 0) {
				if (tmp == 2 || tmp == 4 || tmp == 5) {
					continue;
				}
			}
			else if (i == 1) {
				if (tmp == 2 || tmp == 6 || tmp == 7) {
					continue;
				}

			}
			else if (i == 2) {
				if (tmp == 3 || tmp == 5 || tmp == 6) {
					continue;
				}
			}
			else if (i == 3) {
				if (tmp == 3 || tmp == 4 || tmp == 7) {
					continue;
				}
			}

			int nx = pos_x + dx[i];
			int ny = pos_y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
				if (!visited[ny][nx] && map[ny][nx]) {
					//이번엔 반대로, 움직인 좌표에서 현재 위치 터널로 들어올 수 있는 곳만 연산
					if (i == 0) {
						if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5) {
							q.push({ {ny,nx},val_time + 1 });
							visited[ny][nx] = 1;

						}
					}
					else if (i == 1) {
						if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 6 || map[ny][nx] == 7) {
							q.push({ {ny,nx},val_time + 1 });
							visited[ny][nx] = 1;
						}

					}
					else if (i == 2) {
						if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 5 || map[ny][nx] == 6) {
							q.push({ {ny,nx},val_time + 1 });
							visited[ny][nx] = 1;
						}
					}
					//하-> 현재 좌표로 이동가능한 
					else if (i == 3) {
						if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 7) {
							q.push({ { ny,nx },val_time + 1 });
							visited[ny][nx] = 1;
						}
					}
				}
			}


		}

	}
}
