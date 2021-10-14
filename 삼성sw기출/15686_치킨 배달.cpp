#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
#define endl '\n'
int n, m, r, c, map[51][51], min_val=1000000;
vector<pair<int, int>>home;
vector<pair<int, int>>chicken;
vector<pair<int, int>>v;
int visited[14];
void dfs(int idx, int cnt);
int func();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//������ ���ظ��ߴµ�, m���� 1,2,3���� Ž���ϸ鼭 ���� �����ϴ°� �ƴ϶�
	//�׳� m�� ��� ��Ž �������(����)
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				home.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				chicken.push_back(make_pair(i, j));

		}
	}
	dfs(0, 0);
	cout << min_val << endl;
	return 0;
}
void dfs(int idx, int cnt)
{

	if (cnt == m) {
		min_val = min(min_val, func());
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (!visited[i]) {
			visited[i] = 1;
			v.push_back(chicken[i]);
			dfs(i, cnt + 1);
			visited[i] = 0;
			v.pop_back();
		}
	}
}
int func()
{
	int sum = 0;
	//2�� �������� m���� ġŲ���� �������� ��� �Ÿ��� ��� �ּڰ� ��ȯ
	//�߸������, ġŲ������->�������� �ƴ� ��->ġŲ�� ���� �Ÿ��� �����
	//���̰� ����;

	for (int i = 0; i < home.size(); i++) {
		int x = home[i].first;
		int y = home[i].second;
		int temp = 1000000;
		for (int j = 0; j < v.size(); j++) {
			int xx = v[j].first;
			int yy = v[j].second;
			temp = min(temp, abs(xx - x) + abs(yy - y));
		}
		sum += temp;
	}
	return sum;
}