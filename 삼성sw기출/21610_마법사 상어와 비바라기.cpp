#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
int n, m, d, s;
int map[50][50];
int visited[50][50];

vector<pair<int, int>>v;
//��ǥ�� ������ �°� ������

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { -0,-1,-1,-1,0,1,1,1 };
void move();
void water();
void cloud();
int check(int pos);
int water_total();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	//�񱸸�, -1 ���ִ°� ��ǥ�谡 0~n������(1~n�� �ƴ�)
	v.push_back({ n-1,1-1 });
	v.push_back({ n-1,2-1 });
	v.push_back({ n - 1-1,1-1 });
	v.push_back({ n - 1-1,2-1 });
	for (int i = 0; i < m; i++) {
		cin >> d >> s;
		move();
		water();

		v.clear();
		cloud();
		memset(visited, 0, sizeof(visited));
	}
	cout << water_total() << endl;
	return 0;
}
void move()
{
	//�����س��� ���������� ������ ������ �� �밢�� üũ�� �� ��ǥ�� ���������
	vector<pair<int, int>>temp = v;
	v.clear();

	for (int i = 0; i < temp.size(); i++) {
		int y = temp[i].first;
		int x = temp[i].second;
		for (int i = 0; i < s; i++) {
			y = y + dy[d - 1];
			y=check(y);

			x = x + dx[d - 1];
			x=check(x);
		}
		visited[y][x] = 1;
		v.push_back({ y,x });
		map[y][x]++;
	}
}
int check(int pos)
{
	if (pos == -1)
		return n-1;
	if (pos == n )
		return 0;
	
	//�̰� �����༭ Ʋ��;;
	return pos;
}

void water()
{
	for (int i = 0; i < v.size(); i++) {
		int y = v[i].first;
		int x = v[i].second;
		int cnt = 0;
		//2,4,6,8�� �밢��idx(0~9�̹Ƿ� -1��)
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[2*i+1];
			int nx = x + dx[2*i+1];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n)
				if (map[ny][nx])cnt++;
		}
		map[y][x] += cnt;
	}
}
void cloud()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] >= 2 && !visited[i][j])
			{
				map[i][j] -= 2;
				v.push_back({ i,j });
			}
		}
	}
}
int water_total()
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += map[i][j];
		}
	}return sum;
}