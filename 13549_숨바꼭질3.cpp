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
	//bfs는 기본적으로 엣지의 가중치가 같아야함
	//이 문제처럼 연산시간(엣지가중치)가 다른 순간 다른 수식으로 풀어야함
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	 res=bfs();
	cout << res << endl;
	
}
int bfs()
{
	//데이터,데이터담을 저장소, 규칙(없=기본=오름차순, greater=내림차순))
	//최소 거리를 담아야하므로 <최소거리,현재위치>담음
	//최소거리를 찾아야하므로 오름차순 즉, greater붙여줌
	priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push(make_pair(0, n));
	visited[n] = 1;
	while (!q.empty()) {
		int min_val = q.top().first;
		int current_pos = q.top().second;
		q.pop();
		//만약 도착해쓰면 탈출
		if (current_pos == k) {
			return min_val;
		}

		//중요//
		//연산 순서도 중요함, current_pos*2부분을 맨위에놓지 않으면 오답, 예제 답도 4로나옴
		//최단거리를 큐에 중복없이 집어넣어야 하는데, 
		//current_pos+1이나 current_pos-1뒤에 연산식을 넣으면 +1, x-1연산식의 visited에 의해 
		//최단거리를 구할 때 current_pos*2의 수식이 if문에서 탈출되는 경우 발생(이미 visited=1되어있으므로)
		//따라서 맨 위에 넣어서 큐에 넣어진 *2연산결과의 최단거리를 체킹하고
		//나머지 결과를 체킹하지 않아야함


		//우선순위 큐 이므로 시간0인 2*x연산도 계산시간 증가시키지않은 채 큐에넣으면됨
		if (current_pos * 2 < MAX && !visited[current_pos * 2]) {
			//min_val는 증가되지않음
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