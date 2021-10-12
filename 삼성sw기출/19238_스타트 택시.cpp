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
//�°��� ����/���� ��ǥ
//�ýÿ� ���� ���� ������ �ʿ����?-> ����, �� �Լ����� ť�� ���� ����

//��� ��ǥ�� �����Ϸ��� �迭�� �޾ƾ���(��ȣ���� �̿��ϹǷ�)
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
			//�ʿ� �°��� ��ȣ�� �����ǵ� 1�� ���� �ǹ��ϹǷ� -1�� �ٲ���
			if (map[i][j] == 1)map[i][j] = -1;
		}
	}
	
	//��ǥ�� �򰥸��� y,x�ȹٲٰ� �׳� ��

	cin >> taxi_x >> taxi_y;
	int start_x, start_y, end_x, end_y;
	for (int i = 1; i <= m; i++) {
		cin >> start_x >> start_y >> end_x >> end_y;
		people[i].push_back({ {start_x,start_y},{end_x,end_y} });
		//�ʿ� �մ��� ���̵� ����
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
	//�Ѹ��� ã���� �Ÿ� �迭�� �ʱ�ȭ ���Ѿ���
	memset(visited, 0, sizeof(visited));
	queue<pair<pair<int, int>, pair<int, int>>>q;
	//���� ��ǥ, ������������ �Ÿ�, ���� ���ᷮ
	q.push({ {taxi_x,taxi_y},{0,gage} });
	visited[taxi_x][taxi_y] = 1;
	

	//�Ÿ�, ��, ��,id(�� ������ �ؾ� ������ ��)
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

		//�մ��� ã���� �� ������ ��ƾ���(�߰� ���� �ʿ伺(���� ������))
		if (map[x][y])v.push_back({ {dist,x},{y,map[x][y]} });
		if (fuel == 0)continue;//�յھ翷 �� Ž���ϴϱ� break�ɸ� �ȵ� , continue��!

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n && !visited[nx][ny]&&map[nx][ny]!=-1) {
				visited[nx][ny] = 1;
				q.push({ {nx,ny},{dist + 1,fuel - 1} });
			}
		}
	}
	//���Ϳ� ������ �Ұ����Ѱ���(�¿� �� ������ -1�����ϴ� ����)
	if (v.size() == 0)
	{
		return -1;
	}
	sort(v.begin(), v.end());
	//������ ���� 0 ó��
	map[v[0].first.second][v[0].second.first] = 0;
	//���ߵǴ� ����=�Ÿ�
	gage = gage - v[0].first.first;
	
	id = v[0].second.second;
	return id;
	
	//ã������ ���� ���������� ����
	

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
		//������-> ���ᷮ����&&�ý��� ����ġ�� ������ġ(������)�� ����
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