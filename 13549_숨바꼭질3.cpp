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
	//예제의 정답은 5->4(+1)->8->16->17(+1)==>답:2
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
	//visited는 [idx]에 도착한 시간
	//시작을 1이 아닌 0으로 처리,이미 도착했으므로(=체크여부가 아닌 도착시간)
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		//도착했을때
		if (x == k) {
			res = visited[k];
			return;
		}
		//x+1, x-1 에 도착한 시간이 x에 도착한 시간+1보다 크면 갱신
		//why?
		//어짜피 3에서 4로 간다고 생각하면 +1이 되는데,
		//만약 4에 도착한 시간이 3에 도착한 시간+1(=x+1을 밟았다면 visited[x]++ 해주므로(방문 체크) )
		//근데 x-1,x+1,x*2를 탐색하다보면 visited[x+1/x-1]가 visited[x]+1보다 커지는 경우 생김=>  visited에 그 지점 도착 최단거리 갱신
		if (x + 1 < MAX && visited[x + 1] > visited[x] + 1)
		{
			visited[x + 1] = visited[x] + 1;
			q.push(x + 1);
		}
		if (x - 1 >= 0 && visited[x - 1] > visited[x] + 1) {
			visited[x - 1] = visited[x] + 1;
			q.push(x - 1);
		}
		//x*2는 0초인데 조건문을 어떻게 작성할까?=> visited[x]+1은 밟고나서 밟은거리(1씩)를 체크해주는데
		//x*2는 0초이므로 visited[x]+1가 아닌 visited[x]와 비교
		if (x * 2 < MAX && visited[x * 2] > visited[x]) {
			visited[x*2] = visited[x];
			q.push(x*2);
		}
	}
	
	
}