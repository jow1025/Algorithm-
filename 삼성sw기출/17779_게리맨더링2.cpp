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

	//������ �а� ��� �ذ����� �����ϴ°� �߿��� ����
	//���� ����� ���а� dfs�� Ž���� �������������� �̹� ���ǳʰ�..
	//������ �����ص� for�������� �����°� ��


	//x+d1+d2<=n�� �������� x-n<=-d1-d2�ε�, d1+d2>=2�̹Ƿ�
	for (int x = 1; x <= n - 2; x++) {
		//y+d2<=n�� �������� y-n<=-d2�ε�, d2>=1�̹Ƿ�
		for (int y = 2; y <= n - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= n - x - 1; d1++) {
				for (int d2 = 1; d2 <= n - x - 1 && d2 <= n - y; d2++) {
					memset(people, 0, sizeof(people));
					for (int r = 1; r <= n; r++) {
						for (int c = 1; c <= n; c++) {
							if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x))) {
								people[0] += map[r][c];
							}
							//2�� ���ű�
							else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x))) {
								people[1] += map[r][c];
							}
							//3�� ���ű�
							else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))) {
								people[2] += map[r][c];
							}
							//4�� ���ű�
							else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) {
								people[3] += map[r][c];
							}
							//5�� ���ű�
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
