#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define endl '\n'
int t, n, map[20][20], visited[101];
int dx[4] = { -1,1,1,-1 };
int dy[4] = { 1,1,-1,-1 };
//����,����,���,�»�
int ans;
//���� ��ġ, dfs�� ������ 
void dfs(int y, int x,int target_y,int target_x, int line,int cake);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;

	for (int cnt = 1; cnt <= t; cnt++) {
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		ans = -1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
					if (j == 0)continue;//1�� ���� ����
					if (j == n - 1)continue;//n-1�� ���� ����
					if (i == n - 2)continue;//n-2�� ���� ����
					if (i == n - 1)continue;//n-1�� ���� ����
				//����Ʈ ���� �ߺ� üũ
				visited[map[i][j]] = 1;
				//line�� 3�� �Ǹ� �簢��
				dfs(i, j,i,j,0,1);
				visited[map[i][j]] = 0;
			}
		}


		cout << '#' << cnt << " " << ans<<endl;
	}
	return 0;
}
void dfs(int y, int x, int target_y, int target_x, int line, int cake)
{

	/*if (line > 3)
		return;*/

	//target ��ġ�� y,x �� ���� ���� ����(�� �ڵ������ y,x��ǥ���� �����ϴ� �簢���� �ƴ� �׳� �簢�� ����Ȯ��)
	//�Ʒ� if������ �簢�� üũ�ϴ� �ڵ尡 ny,nx���� �� ���� ���� �ڿ� �־����(�տ� ����Ǿ��ٸ� ��3�� ���¿��� ���� �������� ����)
	//line==3�� �ǹ̴� �������� ������4��(0,1,2,3) ��¶�
	
	int ny = y + dy[line];
	int nx = x + dx[line];
	if (line == 3) {
		if (ny == target_y && nx == target_x) {
			ans = max(ans, cake);
			return;
		}
	}

	//Ž��
	
		if (ny >= 0 && nx >= 0 && ny < n && nx < n&&!visited[map[ny][nx]]) {
			visited[map[ny][nx]] = 1;
			//���� ������ ���� line�� �״��+ line ������ 0~4���� ���� ������ ��Ÿ���⵵��
			dfs(ny, nx, target_y, target_x, line, cake + 1);
			//2���� dfs���� line<3���ǹ� �ȿ� �� ������ �ȵ�
			//�������� ���� line������ ��ȭ���� Ž���� ��� �����ϴ� ���̰� ���� ���� line++�ϸ鼭 �����ϴ°�
			
			if (line < 3) {
				//dfs(ny, nx, target_y, target_x, line, cake + 1);
				//������ ���� ��	
				dfs(ny, nx, target_y, target_x, line + 1, cake + 1);
				
			}
			visited[map[ny][nx]] = 0;
		}
		
}
