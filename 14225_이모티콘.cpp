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
	//화면,클립보드,최소시간
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
		//case 1: 화면에 있는 이모티콘 -> 클립보드복사
		//제약: 화면에 있는 이모티콘 수가

		//범위가 약간 헷갈리는데, 내가 이해한 것은
		//화면에 최대 1000개까지 띄울수 있으니까
		//S가 1001일때 현재 화면에 1002개가 있는 경우, 하나를 빼서 1001개를 못만든다고 이해
		//즉,화면에는 최대 1000개가 있을수 있는거임 
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
		//case 2: 클립에 있는 것을 붙여넣기
		//이 경우 역시 board+display가 1000개가 넘어가는 경우가 존재X(불가)
		//예제 중 입력값이 6일때 답이 5인걸보니 클립보드->화면에 붙여넣고나서 클립보드가 비워지는게 아님
		//따라서 visited[][0]=1같은 생각을 하면안됨(붙여넣고나서 보드에는 0개가 있다(x))
		if (board && board + display <= 1000) {
			if (!visited[display + board][board]) {
				visited[board + display][board] = 1;
				q.push(make_pair(make_pair(display + board, board), min_time + 1));
			}
		}
		//case 3번 조건식을 써보니 case1과 조건이 같아서 코드를 위로 올려줌
	}
}