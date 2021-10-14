#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
#define endl '\n'
int n, m, r, c, map[51][51], min_val=1000000;
vector<pair<int, int>>home;
vector<pair<int, int>>chicken;
vector<pair<int, int>>v;
int visited[14];
void dfs(int idx, int cnt);
int func();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//문제를 이해못했는데, m개를 1,2,3개씩 탐색하면서 답을 도출하는게 아니라
	//그냥 m개 골라서 완탐 돌리면됨(조합)
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				home.push_back(make_pair(i, j));
			else if (map[i][j] == 2)
				chicken.push_back(make_pair(i, j));

		}
	}
	dfs(0, 0);
	cout << min_val << endl;
	return 0;
}
void dfs(int idx, int cnt)
{

	if (cnt == m) {
		min_val = min(min_val, func());
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (!visited[i]) {
			visited[i] = 1;
			v.push_back(chicken[i]);
			dfs(i, cnt + 1);
			visited[i] = 0;
			v.pop_back();
		}
	}
}
int func()
{
	int sum = 0;
	//2중 포문으로 m개의 치킨집과 집까지의 모든 거리를 재고 최솟값 반환
	//잘못얘기함, 치킨집시작->집도착이 아닌 집->치킨집 도착 거리를 재야함
	//차이가 있음;

	for (int i = 0; i < home.size(); i++) {
		int x = home[i].first;
		int y = home[i].second;
		int temp = 1000000;
		for (int j = 0; j < v.size(); j++) {
			int xx = v[j].first;
			int yy = v[j].second;
			temp = min(temp, abs(xx - x) + abs(yy - y));
		}
		sum += temp;
	}
	return sum;
}