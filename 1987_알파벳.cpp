#include<iostream>
#include<algorithm>
using namespace std;
#define endl '\n'
char map[20][20];
int visited[26];
int ans,r, c;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void dfs(int y, int x, int cnt);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!visited[map[i][j] - 'A']) {
				visited[map[i][j]-'A']=1;
				dfs(0, 0, 1);
				
			}
		}
	}
	cout << ans << endl;
	
	
}
void dfs(int y, int x, int cnt) 
{
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx=x + dx[i];
		if (nx >= 0 && ny >= 0 && ny < r && nx < c&&!visited[map[ny][nx]-'A']) {
				visited[map[ny][nx] - 'A'] = 1;
				dfs(ny, nx, cnt + 1);
				visited[map[ny][nx] - 'A'] = 0;
			
		}
	}

}