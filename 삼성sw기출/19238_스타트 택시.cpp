#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define endl '\n'
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
using namespace std;
int n,id, m,ans,taxi_x,taxi_y,gage,map[21][21],visited[21][21];
//승객의 시작/도착 좌표
//택시에 대한 벡터 정보는 필요없나?-> 없음, 각 함수에서 큐로 진행 가능

//사람 좌표를 저장하려면 배열로 받아야함(번호까지 이용하므로)
vector<pair<pair<int, int>, pair<int, int>>>people[500];
int search_people();
bool bfs(int a,int b,int c, int d);
int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> gage;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			//맵에 승객들 번호를 찍을건데 1은 벽을 의미하므로 -1로 바꿔줌
			if (map[i][j] == 1)map[i][j] = -1;
		}
	}
	
	//좌표가 헷갈리면 y,x안바꾸고 그냥 ㄱ

	cin >> taxi_x >> taxi_y;
	int start_x, start_y, end_x, end_y;
	for (int i = 1; i <= m; i++) {
		cin >> start_x >> start_y >> end_x >> end_y;
		people[i].push_back({ {start_x,start_y},{end_x,end_y} });
		//맵에 손님의 아이디를 찍음
		map[start_x][start_y] = i;
		
	}
	//sort(temp.begin(), temp.end());
	int res;
	for (int i = 1; i <= m; i++) {
		res=search_people();
		if (res == -1) {
			cout << -1 << endl;
			return 0;
		}
		bool flag= bfs(people[res].front().first.first, people[res].front().first.second, people[res].front().second.first, people[res].front().second.second);
		if (flag == false) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << gage << endl;

	return 0;
}

int search_people()
{
	int id;
	//한명을 찾으면 거리 배열을 초기화 시켜야함
	memset(visited, 0, sizeof(visited));
	queue<pair<pair<int, int>, pair<int, int>>>q;
	//현재 좌표, 도착지까지의 거리, 현재 연료량
	q.push({ {taxi_x,taxi_y},{0,gage} });
	visited[taxi_x][taxi_y] = 1;
	

	//거리, 행, 열,id(이 순서로 해야 정렬이 됨)
	vector<pair<pair<int, int>, pair<int,int>>>v;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second.first;
		int fuel = q.front().second.second;
		if (fuel < 0) {
			return -1;
		}
		q.pop();

		//손님을 찾았을 때 정보를 담아야함(추가 벡터 필요성(위에 선언함))
		if (map[x][y])v.push_back({ {dist,x},{y,map[x][y]} });
		if (fuel == 0)continue;//앞뒤양옆 다 탐색하니깐 break걸면 안됨 , continue로!

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n && !visited[nx][ny]&&map[nx][ny]!=-1) {
				visited[nx][ny] = 1;
				q.push({ {nx,ny},{dist + 1,fuel - 1} });
			}
		}
	}
	//벡터에 없으면 불가능한거임(태울 수 없으면 -1종료하는 조건)
	if (v.size() == 0)
	{
		return -1;
	}
	sort(v.begin(), v.end());
	//도착한 지점 0 처리
	map[v[0].first.second][v[0].second.first] = 0;
	//빼야되는 연료=거리
	gage = gage - v[0].first.first;
	
	id = v[0].second.second;
	return id;
	
	//찾았으니 이제 도착지까지 ㄱㄱ
	

}
bool bfs(int a, int b, int c, int d)
{
	memset(visited, 0, sizeof(visited));
	queue < pair < pair<int, int>, pair<int, int>>>q;
	q.push({ {a,b},{0,gage} });
	visited[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second.first;
		int fuel = q.front().second.second;
		if (fuel < 0) {
			return false;
		}
		q.pop();
		//도착시-> 연료량설정&&택시의 현위치를 지금위치(목적지)로 변경
		if (x == c && y == d) {
			gage = gage - dist;
			if (gage < 0) {
				return false;
			}
			gage = gage + (dist * 2);
			taxi_x = x;
			taxi_y = y;
			return true;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n && !visited[nx][ny] && map[nx][ny] != -1) {
				visited[nx][ny] = 1;
				q.push({ {nx,ny},{dist + 1,fuel - 1} });
			}
		}
	}
	return false;
}