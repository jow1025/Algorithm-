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
	//visited[start] = 1; -> while문 안에 중복되므로 없어도됨

	//일반적인 bfs처럼 방문 안한곳 방문처리(visited체크)하고 푸쉬하면 
	//방문한곳을 다시 방문 안하게 되는 오류상황 발생
	//ex) n=1, k=3일 때 큐에 (2,1),(2,1)이 푸쉬되는데(1+1, 1*2)
	//1+1 체크하면 1*2인 경우는 무시됨
	// 이를 해결하려면 visited 체크를 푸쉬할때가 아닌 while문안에 체크

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		visited[x] = 1;
		q.pop();
		
		//그냥 단순히 n==k일때의 조건문 하나만 완성시키면
		//x=k가 되는 모든 경우의수를 탐색할 수 있으므로 경우를 나눠야함
		//실제로 n=5,k=17일 때 5,4로 출력되는 오류
		
		 //1) 맨 처음 도착(x==k일때로)-> min_time갱신, 가짓수res++;
		 //2) 이미 도착한 전적이 있고 똑같은 최소시간으로 도착한 경우
		
		//2)->1)순으로 진행해야 함
		
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