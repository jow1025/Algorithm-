#include<iostream>
using namespace std;
int n, m, w, b, cnt;
char map[100][100];
int visited[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void dfs(int y, int x);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	//1부터 시작해도
	//[j]문자열(가로)는 0부터 시작함(함정 ....)
	//평소처럼 1부터 진행할 때 j처리하기 까다로워서 그냥 0부터 진행
	//문제를 잘읽자. n,m입력받고 "n줄이 아닌 m줄 만큼 입력받음"

	for (int i = 0; i < m; i++)
		cin >> map[i];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				if (map[i][j] == 'W') {
					dfs(i, j);
					w += cnt * cnt;
				}
				else if (map[i][j] == 'B') {
					dfs(i, j);
					b += cnt * cnt;
				}
			}
			cnt = 0;
		}
	}
	cout << w << " " << b << endl;
	return 0;
}
void dfs(int y, int x)
{
	char flag = map[y][x];//이 변수를 토대로 구분

	cnt++;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!visited[ny][nx] && ny >=0 && nx >= 0 && ny < m && nx < n) {
			if (map[ny][nx] == flag)//이전 병사와 같은 병사면 계쏙 탐색
				dfs(ny, nx);
		}
	}

}