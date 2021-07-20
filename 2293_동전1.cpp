#include<iostream>
using namespace std;
int n, k;
int coin[101];//동전 배열
int dp[10001];//모든 경우의 수를 따지는 dp
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[0] = 1;//0원을 만드는 경우의수=아무동전도 안쓰는 1가지방법
	//이 배열로 dp start
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> coin[i];

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			//dp[a]=b : a원을 조합하는 b가지의 경우의 수
			//매번 갱신
			//k=3일때 2원을 이용해 3원을 만들려면
			//1원이 무조건 있어야 함을 이용,1원으로 만들 때는 2원이 무조건사용됨을 이용

			dp[j] = dp[j] + dp[j - coin[i]];
		}

	}
	cout << dp[k] << endl;
	return 0;
}