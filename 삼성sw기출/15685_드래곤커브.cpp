#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
int map[101][101], n, x, y, d, g;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int ans;
vector<int>v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		v.clear();
		map[y][x] = 1;
		v.push_back(d);
		for (int j = 0; j < g; j++) {
			int len = v.size() - 1;
			for (int k = len; k >= 0; k--) {
				v.push_back((v[k] + 1) % 4);
			}
		}
		for (int i = 0; i < v.size(); i++) {
			y += dy[v[i]];
			x += dx[v[i]];
			map[y][x] = 1;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
				ans++;
		}
	}
	cout << ans << endl;

	return 0;
}