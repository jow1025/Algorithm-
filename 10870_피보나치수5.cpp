#include<iostream>
using namespace std;
int dp[21];
int func(int n);
int func_dp(int n);
int main()
{
	int n;
	cin >> n;
	/* func: �Ϲ����� Ǯ��
	   func_dp: dp�� �̿��� Ǯ��*/
	//cout << func(n) << endl;
	cout << func_dp(n) << endl;

	return 0;
}
//�Ϲ����� Ǯ��
int func(int n)
{
	if (n == 0) return 0;
	if (n == 1 || n == 2)return 1;
	return func(n - 1) + func(n - 2);
}
int func_dp(int n)
{
	if (n == 0) return 0;
	if (n == 1 || n == 2)return 1;
	//���� ��������� �ٷ� ��ȯ
	if (dp[n] != 0)
		return dp[n];
	return dp[n] = func_dp(n - 1) + func_dp(n - 2);

}
