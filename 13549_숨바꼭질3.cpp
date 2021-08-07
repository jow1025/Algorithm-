#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define endl '\n'
#define MAX 100000+1
int n, k, res;
int visited[MAX];
int bfs();
int main()
{
	//bfs�� �⺻������ ������ ����ġ�� ���ƾ���
	//�� ����ó�� ����ð�(��������ġ)�� �ٸ� ���� �ٸ� �������� Ǯ�����
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	 res=bfs();
	cout << res << endl;
	
}
int bfs()
{
	//������,�����ʹ��� �����, ��Ģ(��=�⺻=��������, greater=��������))
	//�ּ� �Ÿ��� ��ƾ��ϹǷ� <�ּҰŸ�,������ġ>����
	//�ּҰŸ��� ã�ƾ��ϹǷ� �������� ��, greater�ٿ���
	priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push(make_pair(0, n));
	visited[n] = 1;
	while (!q.empty()) {
		int min_val = q.top().first;
		int current_pos = q.top().second;
		q.pop();
		//���� �����ؾ��� Ż��
		if (current_pos == k) {
			return min_val;
		}

		//�߿�//
		//���� ������ �߿���, current_pos*2�κ��� ���������� ������ ����, ���� �䵵 4�γ���
		//�ִܰŸ��� ť�� �ߺ����� ����־�� �ϴµ�, 
		//current_pos+1�̳� current_pos-1�ڿ� ������� ������ +1, x-1������� visited�� ���� 
		//�ִܰŸ��� ���� �� current_pos*2�� ������ if������ Ż��Ǵ� ��� �߻�(�̹� visited=1�Ǿ������Ƿ�)
		//���� �� ���� �־ ť�� �־��� *2�������� �ִܰŸ��� üŷ�ϰ�
		//������ ����� üŷ���� �ʾƾ���


		//�켱���� ť �̹Ƿ� �ð�0�� 2*x���굵 ���ð� ������Ű������ ä ť���������
		if (current_pos * 2 < MAX && !visited[current_pos * 2]) {
			//min_val�� ������������
			q.push({ min_val,current_pos * 2 });
			visited[current_pos * 2] = 1;
		}
		if (current_pos + 1 < MAX && !visited[current_pos + 1]) {

			q.push(make_pair(min_val + 1, current_pos + 1));
			visited[current_pos + 1] = 1;
		}
		if (current_pos-1 >= 0 && !visited[current_pos - 1]) {
			q.push({min_val+1,current_pos-1 });
			visited[current_pos - 1] = 1;
		}
		
	}
}