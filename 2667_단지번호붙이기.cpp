#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1,1 };
int n, visited[26][26], cnt;
string s[26];
void dfs(int y, int x);
int main()
{
	vector<int>v;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]&&s[i][j]=='1') {
				dfs(i, j);
				v.push_back(cnt);
				cnt = 0;

			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}
void dfs(int y, int x)
{
	cnt++;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(ny<n&&nx<n&&ny>=0&&nx>=0){
			if(!visited[ny][nx]&&s[ny][nx]=='1')
			dfs(ny, nx);
		}
	}
}