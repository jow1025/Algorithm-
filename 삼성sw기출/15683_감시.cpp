#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define endl '\n'

using namespace std;
int map[9][9], n, m, ans;
vector<pair<pair<int, int>, int>>v;
void dfs(int cnt);
int count_map();
void func(int y, int x, int dir);
void back_func(int temp[9][9]);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] != 6) {
				v.push_back({ {i,j},map[i][j] });
			}
			else if (map[i][j] == 0)ans++;
		}
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}
void dfs(int cnt)
{
	if (cnt == v.size()) {
		ans = min(ans, count_map());
		return;
	}

	//��:1, ��:2, ��,3, ��:4 
	
	int temp[9][9];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp[i][j] = map[i][j];
			
		}
	}

	
	int y = v[cnt].first.first;
	int x = v[cnt].first.second;
	int dir = v[cnt].second;
	if (dir == 1) {
		for (int i = 1; i <= 4; i++) {
			func(y, x, i);
			dfs(cnt + 1);
			back_func(temp);
			
		}
	}
	else if (dir == 2) {
		//����
		func(y, x, 1);
		func(y, x, 2);
		dfs (cnt + 1);
		back_func(temp);

		//����
		func(y, x, 3);
		func(y, x, 4);
		dfs(cnt + 1);
		back_func(temp);
	}
	else if (dir == 3) {
		func(y, x, 1);
		func(y, x, 3);
		dfs(cnt + 1);
		back_func(temp);

		func(y, x, 1);
		func(y, x, 4);
		dfs(cnt + 1);
		back_func(temp);

		func(y, x, 2);
		func(y, x, 3);
		dfs(cnt + 1);
		back_func(temp);
		
		func(y, x, 2);
		func(y, x, 4);
		dfs(cnt + 1);
		back_func(temp);
	}
	else if (dir == 4) {
		func(y, x, 1);
		func(y, x, 2);
		func(y, x, 4);
		dfs(cnt + 1);
		back_func(temp);

		func(y, x, 1);
		func(y, x, 2);
		func(y, x, 3);
		dfs(cnt + 1);
		back_func(temp);

		func(y, x, 2);
		func(y, x, 3);
		func(y, x, 4);
		dfs(cnt + 1);
		back_func(temp);

		func(y, x, 1);
		func(y, x, 3);
		func(y, x, 4);
		dfs(cnt + 1);
		back_func(temp);
	}
	else if (dir == 5) {

		func(y, x, 1);
		func(y, x, 2);
		func(y, x, 3);
		func(y, x, 4);
		dfs(cnt + 1);
		back_func(temp);

	}

}
int count_map()
{
	int val = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!map[i][j])val++;
		}
	}return val;
}

void func(int y, int x, int dir)
{
	//��������
	

	//��ǥ����... 0~n-1�� �ƴ� 1~n��ǥ�踦 �������
	//
	if (dir == 1) {
	
		for (int i = x + 1; i <= m; i++) {
			if (map[y][i] == 6)break;
			//����ϱ� ������ �� ī�޶� ���� �� ä����
			else if (map[y][i])
				continue;
			else map[y][i] = 10;
		}
	}
	if (dir == 2) {
		for (int i = x - 1; i >= 1; i--) {
			if (map[y][i] == 6)break;
			else if (map[y][i])continue;
			else map[y][i] = 10;
		}
	}
	if (dir == 3) {
		for (int i = y + 1; i <= n; i++) {
			if (map[i][x] == 6)break;
			else if (map[i][x])continue;
			else map[i][x] = 10;
		}
	}
	if (dir == 4) {
		for (int i = y - 1; i >= 1; i--) {
			if (map[i][x] == 6)break;
			else if (map[i][x])continue;
			else map[i][x] = 10;
		}
	}
	
	
}
void back_func(int temp[9][9])
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map[i][j] = temp[i][j];
		}
	}
}