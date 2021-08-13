#include<iostream>
using namespace std;
#define endl '\n'

int dp[10001][4];

int solve(int n, int k)
{
	if (dp[n][k])return dp[n][k];
	for (int i = 4; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			int sum = 0;
			if (j == 1)
			{
				dp[i][j] = 1;
				continue;
			}
			for (int m = 1; m <= j; m++)
			{
				sum += dp[i - j][m];
			}
			dp[i][j] = sum;
		}
	}
	return dp[n][k];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (; T--;)
	{
		int input;
		cin >> input;
		solve(input, 3);
		cout << dp[input][1] + dp[input][2] + dp[input][3] << '\n';
	}
	return 0;
}
