#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
int t, n, k, ans, map[8][8], visited[8][8];
int temp;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void dfs(int y, int x,int height,int idx,int length);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int cnt = 1; cnt <= t; cnt++) {
		cin >> n >> k;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		temp = -1, ans = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				temp = max(map[i][j], temp);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == temp) {
					visited[i][j] = 1;
					dfs(i, j,temp,0,1);
					visited[i][j] = 0;
				}
			}
		}


		cout << '#' << cnt << " " << ans << endl;
	}
	return 0;
	
}
//현재 y,x좌표, 현재 높이, 깎은 지 여부, 최대 등산로길이

void dfs(int y, int x,int height,int idx,int length)
{
	visited[y][x] = 1;
	ans = max(ans, length);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		//맵에 그려놓은 나무 높이를 훼손하지않기 위해 변수선언
		int n_height = map[ny][nx];
		if (!visited[ny][nx] && nx >= 0 && nx < n && ny >= 0 && ny < n) {
			visited[ny][nx] = 1;
			//높이 차에 따른 분기
			if (n_height < height) {
				//visited[ny][nx] = 1;
				dfs(ny, nx, n_height, idx, length + 1);
				
			}
			//높이를 짤라야할 때: 공사여부&&짜르고 높이 재확인
			else  {
				//공사가 끝났을 경우 
				//if (idx == 1)continue;

				if (idx == 0) {
					if (height > n_height - k) {
						idx = 1;
						//최대k만큼 짜를수있는것이므로 최대한 적게짜름(1씩)
						//n_height-=1 가 아님, 현재,다음좌표 각각 높이가 8,10이고 k=1일 때 8>9라서 안됨,
						//최대한 긴 루트를 찾아야하므로 다음 좌표높이는 현재 좌표-1이 최선
						n_height = height - 1;
						dfs(ny, nx, n_height, idx, length + 1);
					}
				}

			}
			visited[ny][nx] = 0;
		}
			
	}
}
	
