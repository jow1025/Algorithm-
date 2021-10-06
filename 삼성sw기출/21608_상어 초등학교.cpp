#include<iostream>
#include<vector>
using namespace std;
struct info {
	int y, x;
	int m, s, d;
};
vector<info>v;
vector<info>map[51][51];
int dx[8] = {0,1,1,1,0,-1,-1,-1  };
int dy[8] = {-1,-1,0,1,1,1,0,-1  };
int dir_t[4] = { 0,2,4,6 };
int dir_f[4] = { 1,3,5,7 };
int N, M, K, r, c,m,s, d, ans;
void move();
int check(int pos);
void func();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		v.push_back({ r,c,m,s,d });
		map[r][c].push_back({ r,c,m,s,d });
	}
	for (int i = 0; i < K; i++)
	{
		move();
		func();
	}
	
	for (int i = 0; i < v.size(); i++)
		ans += v[i].m;
	cout << ans << endl;
	return 0;
}
void move()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j].clear();
		}
	}
	for (int i = 0; i < v.size(); i++)
	{

		int x = v[i].x;
		int y = v[i].y;
		int mass = v[i].m;
		int speed = v[i].s;
		int dir = v[i].d;
		
		for (int k = 0; k < speed; k++) {
			y = y + dy[dir];
			y = check(y);

			x = x + dx[dir];
			x = check(x);
		}
		map[y][x].push_back({ y,x,mass,speed,dir });
		v[i].x = x;
		v[i].y = y; 
	}



}
int check(int pos)
{
	//��ǥ�� 1~n������ �������Ƿ� pos���� ����
	//�̰� ������ Ʋ��;
	if (pos == 0)
		return N ;
	if (pos == N+1)
		return 1;
	return pos;
}
void func()
{
	//���̾ ����v���͸� ����ų� ������� ���� move,func���� �� ���̾ ��ġ ȥ��
	//-> ������
	vector<info>temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//�幮�� ��α� ����
			if (map[i][j].size() ==1) {
				//������ ��ġġ�ʰ� �����ϴ� ���̾�� ��ġǪ��
				temp.push_back(map[i][j][0]);
				continue;
			}
			if (map[i][j].size() == 0)continue;

			//if�� �� �ɷ��� �� �Ʒ����ʹ� �ڿ������� ��ġ�� ���̾�� ���� ������
			int mass_sum = 0;
			int speed_sum = 0;
			bool even = true;
			bool odd = true;
			int cnt = map[i][j].size();

			for (int k = 0; k < map[i][j].size(); k++) {
				mass_sum += map[i][j][k].m;
				speed_sum += map[i][j][k].s;
				if (map[i][j][k].d % 2 == 0)
					odd = false;
				else even = false;
			}
			int mass = mass_sum / 5;
			int speed = speed_sum / cnt;
			if (mass == 0)continue;
			if (even == true || odd == true)
				for (int k = 0; k < 4; k++)temp.push_back({ i,j,mass,speed,dir_t[k] });
			else
				for (int k = 0; k < 4; k++)temp.push_back({ i,j,mass,speed,dir_f[k] });
		
		}
	}
	v = temp;
}