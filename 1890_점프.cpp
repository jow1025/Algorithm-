#include<stdio.h>
int graph[101][101];
long long dp[101][101];
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 0)
				continue;
			dp[i + graph[i][j]][j] += dp[i][j];
			dp[i][j + graph[i][j]] += dp[i][j];

		}
	}
	printf("%lld", dp[n - 1][n - 1]);
}