#include<iostream>
#include<queue>
using namespace std;
int s, res;
int visited[1001][1001];
void bfs(int start);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	bfs(1);
	cout << res << endl;

	return 0;
}
void bfs(int start)
{
	//ȭ��,Ŭ������,�ּҽð�
	queue<pair<pair<int, int>, int>>q;
	q.push(make_pair(make_pair(start, 0), 0));
	visited[1][0] = 1;
	while (!q.empty()) {
		int display = q.front().first.first;
		int board = q.front().first.second;
		int min_time = q.front().second;
		q.pop();
		if (display == s) {
			res = min_time;
			return;
		}
		//case 1: ȭ�鿡 �ִ� �̸�Ƽ�� -> Ŭ�����庹��
		//����: ȭ�鿡 �ִ� �̸�Ƽ�� ����

		//������ �ణ �򰥸��µ�, ���� ������ ����
		//ȭ�鿡 �ִ� 1000������ ���� �����ϱ�
		//S�� 1001�϶� ���� ȭ�鿡 1002���� �ִ� ���, �ϳ��� ���� 1001���� ������ٰ� ����
		//��,ȭ�鿡�� �ִ� 1000���� ������ �ִ°��� 
		if (display && display <= 1000) {
			if (!visited[display][display]) {
				visited[display][display] = 1;
				q.push(make_pair(make_pair(display, display), min_time + 1));
			}
			if (!visited[display - 1][board]) {
				visited[display - 1][board] = 1;
				q.push(make_pair(make_pair(display - 1, board), min_time + 1));
			} 
		}
		//case 2: Ŭ���� �ִ� ���� �ٿ��ֱ�
		//�� ��� ���� board+display�� 1000���� �Ѿ�� ��찡 ����X(�Ұ�)
		//���� �� �Է°��� 6�϶� ���� 5�ΰɺ��� Ŭ������->ȭ�鿡 �ٿ��ְ��� Ŭ�����尡 ������°� �ƴ�
		//���� visited[][0]=1���� ������ �ϸ�ȵ�(�ٿ��ְ��� ���忡�� 0���� �ִ�(x))
		if (board && board + display <= 1000) {
			if (!visited[display + board][board]) {
				visited[board + display][board] = 1;
				q.push(make_pair(make_pair(display + board, board), min_time + 1));
			}
		}
		//case 3�� ���ǽ��� �Ẹ�� case1�� ������ ���Ƽ� �ڵ带 ���� �÷���
	}
}