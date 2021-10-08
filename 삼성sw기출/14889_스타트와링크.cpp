#include<iostream>
#include<algorithm>
using namespace std;
int map[20][20];
bool check[20];
int min_val = 10001;
int n;
void dfs(int cnt, int pos);

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	dfs(0, 0);
	cout << min_val << '\n';
}
void dfs(int cnt, int pos)
{
	if (cnt == n/2) {
		int start = 0, link = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i]&&check[j])start += map[i][j];
				if (!check[i]&&!check[j])link += map[i][j];
			}
		}
		int val = abs(start - link);
		min_val = min(min_val, val);
		return;
		
	}
	for (int i = pos; i < n; i++) {
		check[i] = true;
		dfs(cnt + 1,i+1);
		check[i] = false;

	}
}