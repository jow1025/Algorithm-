#include<queue>
#include<iostream>
#include<algorithm>
#include<cstring>
#define endl '\n'
using namespace std;
int map[52][52];
int n, m, max_val, visited[52][52];

//오랜만에 순간 8좌표를 헷갈렸음..
//사각형을 9개로 나눈다음 배열idx기준 1.1좌표를 0.0으로 생각해보면됨(0,0인 좌표는 빼고)
int dx[8] = { -1,-1,-1,1,1,1,0,0 };
int dy[8] = { -1,1,0,-1,0,1,-1,1 };
//모든 0좌표에서 1을 만났을 때 거리를 다 조사한다.
//bfs==최단거리 보장이므로 최단거리가 갱신됨
//모든 0좌표->1까지의 bfs로 구한 최단거리 중에서 제일 긴게 답임
//최초0,0좌표에서 구하는게 아니라 모든 0좌표에서 구하는 것이므로
//매 연산마다 visited배열을 초기화 시켜줘야함


//굳이 벡터에 안넣고 완전탐색 돌려도되는데
//최악의 경우 모든 좌표에 오직 하나의 좌표만이 0일때
//모든 좌표를 탐색해야되는데, 벡터에 0인값만 가진좌표만 넣고 돌리면
//한번만 탐색해도 끝이니 벡터에 넣어주자 그냥.


//좌표를 헷갈리지말자.
//(x,y)를 (y,x)로 놓고 풀때, 정말 주의해야함
//bfs함수에서 모든 x,y,nx,ny를 꺼꾸로 쓰면 답이 이상한 값이 나옴
//왜그럴까?-> 잘 생각해보자 

//결론: 73행에서 nx<
vector<pair<int, int>>v;
int bfs(int y, int x);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			//0인좌표를 넣음
			if (map[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < (int)v.size(); i++) {
		memset(visited, 0, sizeof(visited));
		int val = bfs(v[i].first, v[i].second);
		max_val = max(val, max_val);
	}
	cout << max_val << endl;
	return 0;
	
}
int bfs(int y, int x)
{
	//최대한 전역 변수를 쓰지말아보자. 큐에 카운팅 cnt변수를 넣어서 써보자.
	queue < pair<pair<int, int>, int>>q;
	visited[y][x] = 1;
	q.push({ {y,x},0 });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (map[y][x] == 1)return cnt;
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			//아래 좌표 범위를 잘 살펴보자. 습관처럼 그냥 처음에 x를n, y를 m처럼 입력받았으니
			//nx<=n, ny<=m으로 잡으면? ===> 그럴꺼면 왜 bfs함수에서 y,x를 뒤집었음?? ==x(n)을 y좌표로, y(m)을 x좌표로 생각해서 bfs에서 바꿔썼기 때문에
			//좌표를 바꿔줘야함. 즉, nx는 처음 입력받은 x좌표계였으나 x를 y로, y를 x로 바꿔서 풀었기 때문에 nx의 범위는 n이 아닌 m임, ny도 마찬가지

			//너무 이런 실수를 자주함. 생각을 하면서 풀자.(x를 y좌표계로사용, y를 x좌표계로 사용하려고 x,y를 바꿨기 때문에 당연히 x,nx는 n이아닌 m범위임
			
			if (ny >= 1 && nx >= 1 && nx <= m && ny <= n) {
				if (!visited[ny][nx]) {
					visited[ny][nx] = 1;
					q.push({ {ny,nx},cnt + 1 });
				}
				
			}
		}
	}
}