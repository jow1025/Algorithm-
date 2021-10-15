#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#define endl '\n'
using namespace std;
struct shark {
	int x;
	int y;
	int size;
	int eat_cnt;
};

shark s;
vector<pair<pair<int,int>,int>>can_eat;
int n, map[21][21], ans;
int visited[21][21];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void bfs(int x, int y);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				s.x = i;
				s.y = j;
				s.size = 2;
				s.eat_cnt = 0;
			}
		}
	}
	while (1) {
		//탐색
		bfs(s.x, s.y);	
		if (can_eat.empty()) {
			cout << ans << endl;
			break;
		}
		else  {
			map[s.x][s.y] = 0;
			map[can_eat.front().first.second][can_eat.front().second] = 9;
			s.x = can_eat.front().first.second;
			s.y = can_eat.front().second;
			s.eat_cnt++;
			ans += can_eat.front().first.first;
			if (s.eat_cnt == s.size) {
				s.eat_cnt = 0;
				s.size += 1;
			}
		}
	}
	
}

void bfs(int x, int y)
{
	//위치 ,거리
	queue<pair<pair<int, int>, int>>q;
	can_eat.clear();
	memset(visited, 0, sizeof(visited));
	q.push({ {x,y},0 });
	visited[x][y] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= n && ny <= n && !visited[nx][ny]) {
				if (map[nx][ny] == 0) {
					visited[nx][ny] = 1;
					q.push({ {nx,ny},dist + 1 });
				}
				else if (map[nx][ny] < s.size) {
					can_eat.push_back({ {dist + 1,nx},ny });
					q.push({ {nx,ny},dist + 1 });
					visited[nx][ny] = 1;
				}
				else if (map[nx][ny] == s.size) {
					visited[nx][ny] = 1;
					q.push({ {nx,ny},dist + 1 });

				}
				//그외 else 는 못먹는 경우 
				
				
				
			}
		}
	}
	//물고기 정보 sort시킴
	sort(can_eat.begin(), can_eat.end());
	//결과로 먹을수 있는 물고기 정보가 can_eat에 담겨있으며
	///이제 먹는 연산 필요


}