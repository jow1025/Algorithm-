#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
int t, n, k, ans, map[8][8], visited[8][8];
int temp;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void dfs(int y, int x,int height,int idx,int length);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int cnt = 1; cnt <= t; cnt++) {
		cin >> n >> k;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		temp = -1, ans = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				temp = max(map[i][j], temp);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == temp) {
					visited[i][j] = 1;
					dfs(i, j,temp,0,1);
					visited[i][j] = 0;
				}
			}
		}


		cout << '#' << cnt << " " << ans << endl;
	}
	return 0;
	
}
//���� y,x��ǥ, ���� ����, ���� �� ����, �ִ� ���α���

void dfs(int y, int x,int height,int idx,int length)
{
	visited[y][x] = 1;
	ans = max(ans, length);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		//�ʿ� �׷����� ���� ���̸� �Ѽ������ʱ� ���� ��������
		int n_height = map[ny][nx];
		if (!visited[ny][nx] && nx >= 0 && nx < n && ny >= 0 && ny < n) {
			visited[ny][nx] = 1;
			//���� ���� ���� �б�
			if (n_height < height) {
				//visited[ny][nx] = 1;
				dfs(ny, nx, n_height, idx, length + 1);
				
			}
			//���̸� ©����� ��: ���翩��&&¥���� ���� ��Ȯ��
			else  {
				//���簡 ������ ��� 
				//if (idx == 1)continue;

				if (idx == 0) {
					if (height > n_height - k) {
						idx = 1;
						//�ִ�k��ŭ ¥�����ִ°��̹Ƿ� �ִ��� ����¥��(1��)
						//n_height-=1 �� �ƴ�, ����,������ǥ ���� ���̰� 8,10�̰� k=1�� �� 8>9�� �ȵ�,
						//�ִ��� �� ��Ʈ�� ã�ƾ��ϹǷ� ���� ��ǥ���̴� ���� ��ǥ-1�� �ּ�
						n_height = height - 1;
						dfs(ny, nx, n_height, idx, length + 1);
					}
				}

			}
			visited[ny][nx] = 0;
		}
			
	}
}
	
