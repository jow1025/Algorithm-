#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct k_info {
	int r, c, s;
};
vector<k_info>v;
vector<int>v1;
#define endl '\n'
int n, m, k;
int map[51][51], visited[6];
int temp_map[51][51];
int min_val = 6000;

void dfs(int cnt);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}
	dfs(0);
	cout << min_val << endl;
	return 0;
}
void dfs(int cnt)
{
	//����, k�� ������ �� �ּڰ� Ȯ��

	//������ �̿��ؼ� k�� ȸ���� �ϼ��ɼ��ִ� �� ������ ���̽� Ȯ��
	//k�� 2�̶�� �ϸ�, �� 2���� ���̽�
	//k�� 3�̶�� �ϸ� �� 6���� ���̽��� �����Ƿ� 
	//��� ��쿡 ���� ȸ������,�ּڰ����� �ϱ� ���� �� copy
	if (cnt == k) {

		//�� ī��
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				temp_map[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < v1.size(); i++) {
			int r = v[v1[i]].r;
			int c = v[v1[i]].c;
			int s = v[v1[i]].s;
			//ȸ��
			for (int d = 1; d <= s; d++) {
				int tmp = temp_map[r - d][c - d];
				//���ʺ�
				for (int i = r - d + 1; i <= r + d; i++) {
					temp_map[i - 1][c - d] = temp_map[i][c - d];
				}
				//�Ʒ��ʺ�
				for (int i = c - d + 1; i <= c + d; i++) {
					temp_map[r + d][i - 1] = temp_map[r + d][i];
				}
				//�����ʺ�
				for (int i = r + d - 1; i >= r - d; i--) {
					temp_map[i + 1][c + d] = temp_map[i][c + d];
				}
				//���ʺ�
				for (int i = c + d - 1; i > c - d; i--) {
					temp_map[r - d][i + 1] = temp_map[r - d][i];
				}
				temp_map[r - d][c - d + 1] = tmp;
			}
		}
			//�ּڰ� Ȯ��
			for (int i = 1; i <= n; i++) {
				int sum = 0;
				for (int j = 1; j <= m; j++) {
					sum += temp_map[i][j];
				}
				min_val = min(min_val, sum);
			}
			return;
		}


	
	

	for (int i = 0; i < v.size(); i++) {
		if (visited[i])continue;
		visited[i] = 1;
		v1.push_back(i);
		dfs(cnt+1);
		v1.pop_back();
		visited[i] = 0;
	}

}