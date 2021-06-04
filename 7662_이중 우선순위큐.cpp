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
		//아래 두개까지 선언하는 건 ok 근데 최댓값/최솟값을 삭제할 때 
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
				//최대힙:2,1 , 최소힙:1,2가 있을 때 최소힙 원소 다 삭제한다고 했을 때
				//최대힙원소를 모두 지워주기위해 visited활용
				//반대 경우도 똑같이.
				if (num == 1) {
					while (!max_pq.empty() && !visited[max_pq.top().second])
						max_pq.pop();
					if (!max_pq.empty()) {
						//빼주고 visited ->false해줘야 min힙에서 똑같이 제거됨
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
				//두 힙에 남은 게 있을 수 있기 때문에 visited:false된것 확인 후 모두 제거
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