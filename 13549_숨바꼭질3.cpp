#include<iostream>
#include<queue>
using namespace std;

#define endl '\n'
#define MAX 100000+1
int n, k, res;
int visited[MAX];
void bfs();
int main()
{
	//������ ������ 5->4(+1)->8->16->17(+1)==>��:2
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	bfs();
	cout << res << endl;
	return 0;
}
void bfs()
{
	queue<int>q;
	q.push(n);
	//visited�� [idx]�� ������ �ð�
	//������ 1�� �ƴ� 0���� ó��,�̹� ���������Ƿ�(=üũ���ΰ� �ƴ� �����ð�)
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		//����������
		if (x == k) {
			res = visited[k];
			return;
		}
		//x+1, x-1 �� ������ �ð��� x�� ������ �ð�+1���� ũ�� ����
		//why?
		//��¥�� 3���� 4�� ���ٰ� �����ϸ� +1�� �Ǵµ�,
		//���� 4�� ������ �ð��� 3�� ������ �ð�+1(=x+1�� ��Ҵٸ� visited[x]++ ���ֹǷ�(�湮 üũ) )
		//�ٵ� x-1,x+1,x*2�� Ž���ϴٺ��� visited[x+1/x-1]�� visited[x]+1���� Ŀ���� ��� ����=>  visited�� �� ���� ���� �ִܰŸ� ����
		if (x + 1 < MAX && visited[x + 1] > visited[x] + 1)
		{
			visited[x + 1] = visited[x] + 1;
			q.push(x + 1);
		}
		if (x - 1 >= 0 && visited[x - 1] > visited[x] + 1) {
			visited[x - 1] = visited[x] + 1;
			q.push(x - 1);
		}
		//x*2�� 0���ε� ���ǹ��� ��� �ۼ��ұ�?=> visited[x]+1�� ����� �����Ÿ�(1��)�� üũ���ִµ�
		//x*2�� 0���̹Ƿ� visited[x]+1�� �ƴ� visited[x]�� ��
		if (x * 2 < MAX && visited[x * 2] > visited[x]) {
			visited[x*2] = visited[x];
			q.push(x*2);
		}
	}
	
	
}