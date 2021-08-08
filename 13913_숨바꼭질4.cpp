#include<iostream>
#include<queue>
#include<vector>
#define endl '\n'
#define MAX 100001
using namespace std;
int n, k;
vector<int>v;
int visited[MAX];
int path[MAX];
int bfs();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	int res = bfs();

	cout << res << endl;
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
	cout << endl;


	return 0;
}
int bfs()
{
	queue<pair<int, int>>q;
	q.push({n,0});
	visited[n]=1;
	while (!q.empty()) {
		int x = q.front().first;
		int min_time = q.front().second;
		
		q.pop();
		if (x == k) {
			//46��~~54�� ������ �ּ�ó���ϰ� ������Ѻ��� �ߺ��������� 5->17�� ���� ����� ��µ�
			//���߿��� �ִܰŸ����� Ž���� ��Ʈ�� ����Ϸ��� ���� ��ġ�� �����ؾ��ϴµ�,
			//�迭[������]=������ġ <<ó�� ������(path[x-1/x+1/x*2] ���� ������ġ�� ���, �̸� �����Ͽ� ���� ����
			//�̷��� ���� �� ���� �׳� �� �迭���� ����غ��� ���� ���� ����
			//�츮�� ���ϰ� ������ path[x-1/x*2/x+1]�� �ƴ�
			//path���� ���� ���밡 ��������Ƿ� ���� ����(������Ʈ)���� �� n(ó���� n�� �����Ƿ�)�� �ƴ� �� ���� ���Ϳ� ��������, �̸� ����ϸ� ��

			int index = x;
			while (1) {
				if (index == n) {//������(=���ʻ��԰� n)ã���� �� ���Ϳ� ��� ��������
					v.push_back(index);
					break;
				}
				v.push_back(index);//���� ���� ���Ϳ� ����
				index = path[index];//���� ���븦 ������ ����
			}
			return min_time;
		}
		if (x + 1 < MAX && !visited[x + 1]) {
			q.push({ x + 1,min_time + 1 });
			visited[x + 1] = 1;
			path[x + 1] = x;
		}
		if (x - 1 >= 0 && !visited[x - 1]) {
			q.push({ x - 1,min_time + 1 });
			visited[x - 1] = 1;
			path[x - 1] = x;
		}
		if (x * 2 < MAX && !visited[x * 2]) {
			q.push({ x * 2,min_time + 1 });
			visited[x *2] = 1;
			path[x * 2] = x;
		}
	}
}