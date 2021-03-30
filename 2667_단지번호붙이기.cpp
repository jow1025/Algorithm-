#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
char map[25][25];
int check[25][25];
int danji[25 * 25 + 1];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n;
int cnt;
int index;
void bfs(int y, int x);

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '1' && check[i][j] == 0)
			{
				bfs(i, j);
				danji[index++] = cnt;
				cnt = 0;
			}
		}
	}
	sort(danji, danji + index);
	cout << index << endl;

	for (int i = 0; i < index; i++)
		cout << danji[i] << endl;
}
void bfs(int y, int x)
{
	queue<pair<int, int>>q;
	q.push({ y,x });
	check[y][x] = 1;
	cnt++;
	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
				if (map[ny][nx] == '1' && check[ny][nx] == 0)
				{
					q.push({ ny,nx });
					check[ny][nx] = 1;
					cnt++;
				}
			}
		}
	}
}