#include<iostream>
#include<queue>
using namespace std;
char map[100][100];
int check[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int n, m;
void bfs(int y, int x);
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	//시작위치가 정해져있으므로 바로 bfs!
	bfs(0, 0);
	//15행 선언후 아래 행 먼저선언하자(어짜피 머릿속으로 이렇게 계산하자고생각했으므로)
	//check배열에 1,0이 아닌 최단칸수담음
	cout << check[n - 1][m - 1] << endl;
}
void bfs(int y, int x)
{
	queue<pair<int, int>>q;
	q.push({ y,x });
	check[y][x] = 1;
	while (!q.empty())
	{
		x = q.front().second;
		y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n)
			{
				//길이있고, 방문하지않았으면 방문 및 최단거리 갱신
				if (map[ny][nx] == '1' && check[ny][nx] == 0)
				{
					q.push({ ny,nx });
					check[ny][nx] = check[y][x] + 1;
				}
			}
		}
	}
}