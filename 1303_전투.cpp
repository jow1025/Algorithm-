#include<iostream>
using namespace std;
int n, m, w, b, cnt;
char map[100][100];
int visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void dfs(int y, int x);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	//1���� �����ص�
	//[j]���ڿ�(����)�� 0���� ������(���� ....)
	//���ó�� 1���� ������ �� jó���ϱ� ��ٷο��� �׳� 0���� ����
	//������ ������. n,m�Է¹ް� "n���� �ƴ� m�� ��ŭ �Է¹���"

	for (int i = 0; i < m; i++)
		cin >> map[i];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				if (map[i][j] == 'W') {
					dfs(i, j);
					w += cnt * cnt;
				}
				else if (map[i][j] == 'B') {
					dfs(i, j);
					b += cnt * cnt;
				}
			}
			cnt = 0;
		}
	}
	cout << w << " " << b << endl;
	return 0;
}
void dfs(int y, int x)
{
	char flag = map[y][x];//�� ������ ���� ����

	cnt++;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!visited[ny][nx] && ny >=0 && nx >= 0 && ny < m && nx < n) {
			if (map[ny][nx] == flag)//���� ����� ���� ����� ��� Ž��
				dfs(ny, nx);
		}
	}

}