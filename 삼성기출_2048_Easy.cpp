#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define endl '\n'
int ans;
int n,map[20][20];
//int temp_map[20][20];
void dfs(int cnt);
void move(int dir);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}
void dfs(int cnt)
{
	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans = max(ans, map[i][j]);
			}
		}
		return;
	}
	int temp_map[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//temp에 원본 저장, map을이용하여 연산
			temp_map[i][j] = map[i][j];
		}
	}
	//회전하고 나서 cnt+1하여 dfs다시
	for (int i = 0; i < 4; i++) {
		move(i);
		dfs(cnt + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = temp_map[i][j];
			}
		}
	}
	//앞뒤양옆 탐색
	
}
void move(int dir)
{
	queue<int>q;
	//왼쪽으로
	if (dir == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j])q.push(map[i][j]);
				map[i][j] = 0;
			}
			int idx = 0;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				if (map[i][idx] == 0)
					map[i][idx] = data;
				else if (map[i][idx] == data) {
					map[i][idx] *= 2;
					idx++;
				}
				else {
					idx++;
					map[i][idx] = data;
				}
			}
		}
	}
	//오른쪽으로
	else if (dir == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (map[i][j])
					q.push(map[i][j]);
				map[i][j] = 0;
			}
			int idx = n - 1;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				if (map[i][idx] == 0) {
					map[i][idx] = data;
				}
				else if (map[i][idx] == data) {
					map[i][idx] *= 2;
					idx--;
				}
				else {
					idx--;
					map[i][idx] = data;
				}
			}
		}
	}
	//위로
	else if (dir == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[j][i])
					q.push(map[j][i]);
				map[j][i] = 0;
			}
			int idx = 0;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				if (map[idx][i] == 0)
					map[idx][i] = data;
				else if (map[idx][i] == data) {
					map[idx][i] *= 2;
					idx++;
				}
				else {
					idx++;
					map[idx][i] = data;
				}
			}
		}
		
	}
	//아래로
	else if (dir == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (map[j][i])
					q.push(map[j][i]);
				map[j][i] = 0;
			}
			int idx = n - 1;
			while (!q.empty()) {
				int data = q.front();
				q.pop();
				if (map[idx][i] == 0)
					map[idx][i] = data;
				else if (map[idx][i] == data) {
					map[idx][i] *= 2;
					idx--;
				}
				else {
					idx--;
					map[idx][i] = data;
				}
			}
		}
	}
}