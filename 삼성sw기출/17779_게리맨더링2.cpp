#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, map[21][21], people[5], ans=5000;
void dfs(int y, int x);
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	//문제를 읽고 어떻게 해결할지 결정하는게 중요한 이유
	//문제 제대로 안읽고 dfs로 탐색할 생각부터했으면 이미 물건너감..
	//문제만 이해해도 for문돌리면 끝나는걸 암


	//x+d1+d2<=n을 뒤집으면 x-n<=-d1-d2인데, d1+d2>=2이므로
	for (int x = 1; x <= n - 2; x++) {
		//y+d2<=n을 뒤집으면 y-n<=-d2인데, d2>=1이므로
		for (int y = 2; y <= n - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= n - x - 1; d1++) {
				for (int d2 = 1; d2 <= n - x - 1 && d2 <= n - y; d2++) {
					memset(people, 0, sizeof(people));
					for (int r = 1; r <= n; r++) {
						for (int c = 1; c <= n; c++) {
							if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x))) {
								people[0] += map[r][c];
							}
							//2번 선거구
							else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x))) {
								people[1] += map[r][c];
							}
							//3번 선거구
							else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))) {
								people[2] += map[r][c];
							}
							//4번 선거구
							else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) {
								people[3] += map[r][c];
							}
							//5번 선거구
							else {
								people[4] += map[r][c];
							}

						}
					}
					sort(people, people + 5);
					ans = min(ans, people[4] - people[0]);
				}
			}
		}
	}
		cout << ans << endl;
}
