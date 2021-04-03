#include<iostream>
using namespace std;
int n;
int map[16][16];
//동 대각선,아래
int dx[3] = { 1,1,0 };
int dy[3] = { 0,1,1 };
//파이프방향
int ans;
void dfs(int y, int x, int dir);
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	///3번쨰 인자는 파이프방향임(0:동:1:대각2:남)
	dfs(0, 1, 0);
	cout << ans << '\n';
}
void dfs(int y, int x, int dir)
{
	if (y == n - 1 && x == n - 1)
	{
		ans++;
		return;
	}
	//3방향에대해 검색
	for (int i = 0; i < 3; i++)
	{
		//파이프가 가로면 가로+대각선만계산
		if (dir == 0 && i == 2)continue;
		//파이프가 세로면 세로+대각선만계산
		if (dir == 2 && i == 0)continue;
		//대각선일 때
		if (i == 1 && (map[y][x + 1] == 1 || map[y + 1][x] == 1))
			continue;

		int ny = y + dy[i];
		int nx = x + dx[i];
		//범위벗어나지않고 이동한 좌표가벽아닐 때
		if (ny < n && nx < n && map[ny][nx] != 1)
			dfs(ny, nx, i);

	}
}