
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<deque>
#include<vector>
#include<queue>
#define endl '\n'
using namespace std;
int n, m, u, v;
vector<int>graph[1000];
int visited[1000];
void dfs(int x);
int main()
{
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
}
void dfs(int x)
{
	visited[x] = 1;
	for (int i = 0; i < graph[x].size(); i++) {
		if(!visited[graph[x][i]]&&graph[x][i])
		dfs(graph[x][i]);
	}
}