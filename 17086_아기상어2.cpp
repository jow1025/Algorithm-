#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
int map[52][52], n, m, max_val;
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int visited[52][52];

//0의 좌표 삽입
vector<pair<int, int>>v;

//0인 좌표를 모두 삽입하고
//그 좌표에서 1을 만났을 때 cnt를 계산,제일 큰 cnt가 답.
//bfs이므로 1까지의 최단거리 보장이므로 자연스럽게 제일 큰 cnt가 정답

using namespace std;
int bfs(int y, int x);
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				v.push_back({ i,j });
		}
	}
	//max_Val과 bfs의 결과를 비교해야함
	for (int i = 0; i < (int)v.size(); i++) {
		//visited를 매번 초기화 시켜야함. 오직 한 좌표에서 시작하는 값을 구하는게 아님
		//모든 빈좌표(0좌표)에서 돌아야 하므로
		memset(visited, 0, sizeof(visited));
		int val = bfs(v[i].first, v[i].second);
		max_val = max(val, max_val);
	}
	cout << max_val << endl;
	return 0;
}
int bfs(int y, int x)
{
	queue<pair<pair<int, int>, int>>q;
	visited[y][x] = 1;
	q.push({ { y,x },0 });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		//1이면 카운팅 반환
		if (map[y][x] == 1)return cnt;

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && n)
		}
	}
}