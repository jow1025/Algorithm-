#include<iostream>
using namespace std;
int fibo(int f);
int dp[40];
int main()
{
	int T;
	int N;
	dp[0] = 0;
	dp[1] = 1;
	cin >> T;
	while (T--)
	{
		cin >> N;
		if (N == 0)
			cout << 1 << " " << 0 << '\n';
		else
			//��ȭ�ļ������� 0�ǰ����� n-1���� �Ǻ���ġ
			//1�� ������ N���� �Ǻ���ġ
			cout << fibo(N - 1) << " " << fibo(N) << '\n';
	}
}
int fibo(int f)
{
	if (f == 0) {
		return 0;
	}
	if (f == 1) {
		return 1;
	}
	if (dp[f] != 0)return dp[f];
	return dp[f] = fibo(f - 1) + fibo(f - 2);
}