#include<iostream>
using namespace std;
int n, a, b,num, map[101][101],visited[101],res;
void dfs(int x);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cin >> a >> b;
		map[a][b] = 1, map[b][a] = 1;
	}
	dfs(1);
	cout << res-1 << endl;
	return 0;
}
void dfs(int x)
{
	visited[x] = 1;
	res++;
	for (int i = 1; i <= n; i++) {
		if (map[x][i] && !visited[i])
			dfs(i);
	}
	
}