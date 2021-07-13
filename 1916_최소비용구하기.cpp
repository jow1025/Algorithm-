#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int INF = 100000000;
vector < pair<int, int>>a[1001];
int d[1001];
void dijkstra(int start);
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, m, v1, v2, w, start, end;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		d[i] = INF;

	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> w;
		a[v1].push_back(make_pair(v2, w));
	}
	cin >> start >> end;
	dijkstra(start);

	cout << d[end] << '\n';
}
void dijkstra(int start)
{
	d[start] = 0;
	priority_queue<pair<int, int>>pq;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		//최단거리가 아니면 skip
		if (d[current] < distance)
			continue;
		for (int i = 0; i < a[current].size(); i++)
		{
			int next = a[current][i].first;
			int next_distance = distance + a[current][i].second;
			if (d[next] > next_distance)
			{
				d[next] = next_distance;
				pq.push(make_pair(-next_distance, next));
			}

		}
	}

}