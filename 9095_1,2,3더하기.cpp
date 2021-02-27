
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<deque>
#include<vector>
#include<queue>

#define endl '\n'
using namespace std;
int dp[11];
int main()
{

	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, num;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 0; i < n; i++) {
		cin >> num;
		for (int i = 4; i <= num; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[num] << endl;
	}
}
