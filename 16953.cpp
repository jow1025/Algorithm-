#include<iostream>
#include<queue>
using namespace std;
int a, b, res = -1;
void bfs(long long start);
//연산할 때 29,30행 값이 int형 범위를 초과할 수 있음;;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	bfs(a);
	cout << res << endl;
	return 0;
}
void bfs(long long  start)
{
	queue < pair<long long, long long >> q;
	q.push(make_pair(start,1));
	while (!q.empty()) {
		long long num = q.front().first;
		long long cnt = q.front().second;
		q.pop();
		if (num == b) {
			res = cnt;
			break;
		}
		
		long long val1 = num * 2;
		long long val2 = num * 10 + 1;//1을 붙인다는 의미
		if (val1 <= b)q.push({ val1,cnt + 1 });
		if (val2 <= b)q.push({ val2,cnt + 1 });
	}
}