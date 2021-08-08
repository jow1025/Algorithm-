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
			//46행~~54행 라인을 주석처리하고 실행시켜보면 중복되지않은 5->17로 가는 길들이 출력됨
			//이중에서 최단거리동안 탐색된 루트를 출력하려면 밟은 위치를 저장해야하는데,
			//배열[밟을곳]=현재위치 <<처럼 저장함(path[x-1/x+1/x*2] 에는 현재위치가 담김, 이를 추적하여 답을 얻음
			//이렇게 담은 뒤 역시 그냥 이 배열값을 출력해보면 많은 값이 나옴
			//우리가 구하고 싶은건 path[x-1/x*2/x+1]이 아님
			//path에는 밟은 자취가 담겨있으므로 자취 값이(추적루트)최초 값 n(처음에 n을 넣으므로)이 아닐 때 까지 벡터에 넣은다음, 이를 출력하면 됨

			int index = x;
			while (1) {
				if (index == n) {//마지막(=최초삽입값 n)찾았을 때 벡터에 담고 빠져나옴
					v.push_back(index);
					break;
				}
				v.push_back(index);//자취 값들 벡터에 삽입
				index = path[index];//밟은 자취를 역으로 추적
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