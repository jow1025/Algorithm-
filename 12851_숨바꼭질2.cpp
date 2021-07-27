#include<iostream>
#include<queue>
using namespace std;
int n, k, min_time, res,visited[100001];
#define endl '\n'
void bfs(int start);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	bfs(n);
	cout << min_time << endl << res << endl;
	return 0;
	

}
void bfs(int start)
{
	queue<pair<int, int>>q;
	q.push({ start,0 });
	//visited[start] = 1; -> while�� �ȿ� �ߺ��ǹǷ� �����

	//�Ϲ����� bfsó�� �湮 ���Ѱ� �湮ó��(visitedüũ)�ϰ� Ǫ���ϸ� 
	//�湮�Ѱ��� �ٽ� �湮 ���ϰ� �Ǵ� ������Ȳ �߻�
	//ex) n=1, k=3�� �� ť�� (2,1),(2,1)�� Ǫ���Ǵµ�(1+1, 1*2)
	//1+1 üũ�ϸ� 1*2�� ���� ���õ�
	// �̸� �ذ��Ϸ��� visited üũ�� Ǫ���Ҷ��� �ƴ� while���ȿ� üũ

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		visited[x] = 1;
		q.pop();
		
		//�׳� �ܼ��� n==k�϶��� ���ǹ� �ϳ��� �ϼ���Ű��
		//x=k�� �Ǵ� ��� ����Ǽ��� Ž���� �� �����Ƿ� ��츦 ��������
		//������ n=5,k=17�� �� 5,4�� ��µǴ� ����
		
		 //1) �� ó�� ����(x==k�϶���)-> min_time����, ������res++;
		 //2) �̹� ������ ������ �ְ� �Ȱ��� �ּҽð����� ������ ���
		
		//2)->1)������ �����ؾ� ��
		
		if (min_time && min_time == cnt && x == k)
			res++;
		if (!min_time && x == k) {
			min_time = cnt;
			res++;
		}

		if (x + 1 <= 100000 && !visited[x + 1])
			q.push({ x + 1,cnt + 1 });
		if (x - 1 >= 0 && !visited[x - 1])
			q.push({ x - 1,cnt + 1 });
		if (2 * x <= 100000 && !visited[2 * x])
			q.push({ 2 * x,cnt + 1 });
		
	}

}