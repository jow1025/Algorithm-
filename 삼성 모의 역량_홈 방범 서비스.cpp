#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
int n, m, t, ans,map[21][21];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int cnt = 1; cnt <= t; cnt++) {
		cin >> n >> m;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		cout << '#' << cnt << " " << ans << endl;
	}

	return 0;
}