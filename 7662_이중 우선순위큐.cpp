#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define endl '\n'
int visited[1000001];
int main()
{
	int n, cnt, num;
	char x;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> cnt;
		//�Ʒ� �ΰ����� �����ϴ� �� ok �ٵ� �ִ�/�ּڰ��� ������ �� 
		priority_queue<pair<int, int>>max_pq;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>min_pq;

		for(int i=0;i<cnt;i++) {
			cin >> x >> num;
			if (x == 'I') {
				max_pq.push({ num,i });
				min_pq.push({ num,i });
				visited[i] = 1;
			}
			else if (x == 'D') {
				//�ִ���:2,1 , �ּ���:1,2�� ���� �� �ּ��� ���� �� �����Ѵٰ� ���� ��
				//�ִ������Ҹ� ��� �����ֱ����� visitedȰ��
				//�ݴ� ��쵵 �Ȱ���.
				if (num == 1) {
					while (!max_pq.empty() && !visited[max_pq.top().second])
						max_pq.pop();
					if (!max_pq.empty()) {
						//���ְ� visited ->false����� min������ �Ȱ��� ���ŵ�
						visited[max_pq.top().second] = 0;
						max_pq.pop();
						
					}
				}
				else {
					while (!min_pq.empty() && !visited[min_pq.top().second])
						min_pq.pop();
					if (!min_pq.empty()) {
						visited[min_pq.top().second] = 0;
						min_pq.pop();
						
					}
				}
				//�� ���� ���� �� ���� �� �ֱ� ������ visited:false�Ȱ� Ȯ�� �� ��� ����
				while (!max_pq.empty() && !visited[max_pq.top().second]){
					max_pq.pop();
				}
				while (!min_pq.empty() && !visited[min_pq.top().second]) {
					min_pq.pop();
				}
			}
			
		}
		if (max_pq.empty() && min_pq.empty())
			cout << "EMPTY" << endl;
		else cout << max_pq.top().first << " " << min_pq.top().first << endl;
	}
	
	
}