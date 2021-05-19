#include<iostream>
using namespace std;
int dp[1000];
int func(int n);
int main()
{
	int n;

	cin >> n;
	cout << func(n);
}
int func(int n)
{
	if (n == 0)return 0;
	if (n == 1)return 1;
	if (n == 2)return 2;
	if (dp[n]!=0)
		return dp[n];
	return dp[n] = (func(n - 1) + func(n - 2)) % 10007;


}