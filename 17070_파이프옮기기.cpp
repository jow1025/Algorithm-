#include<iostream>
using namespace std;
int n;
int map[16][16];
//�� �밢��,�Ʒ�
int dx[3] = { 1,1,0 };
int dy[3] = { 0,1,1 };
//����������
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
	///3���� ���ڴ� ������������(0:��:1:�밢2:��)
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
	//3���⿡���� �˻�
	for (int i = 0; i < 3; i++)
	{
		//�������� ���θ� ����+�밢�������
		if (dir == 0 && i == 2)continue;
		//�������� ���θ� ����+�밢�������
		if (dir == 2 && i == 0)continue;
		//�밢���� ��
		if (i == 1 && (map[y][x + 1] == 1 || map[y + 1][x] == 1))
			continue;

		int ny = y + dy[i];
		int nx = x + dx[i];
		//����������ʰ� �̵��� ��ǥ�����ƴ� ��
		if (ny < n && nx < n && map[ny][nx] != 1)
			dfs(ny, nx, i);

	}
}