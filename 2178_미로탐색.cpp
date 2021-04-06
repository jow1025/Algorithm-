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
	//������ġ�� �����������Ƿ� �ٷ� bfs!
	bfs(0, 0);
	//15�� ������ �Ʒ� �� ������������(��¥�� �Ӹ������� �̷��� ������ڰ���������Ƿ�)
	//check�迭�� 1,0�� �ƴ� �ִ�ĭ������
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
				//�����ְ�, �湮�����ʾ����� �湮 �� �ִܰŸ� ����
				if (map[ny][nx] == '1' && check[ny][nx] == 0)
				{
					q.push({ ny,nx });
					check[ny][nx] = check[y][x] + 1;
				}
			}
		}
	}
}