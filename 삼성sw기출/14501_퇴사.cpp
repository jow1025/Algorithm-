#include<iostream>
#include<algorithm>
using namespace std;
int n, t[16], p[16];
int max_val;
void dfs(int day,int val);
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	dfs(1,0);
	cout << max_val << endl;
	return 0;
}
void dfs(int day,int val)
{
	if (day > n+1) {
		return;
	}
	//7������ �Ⱓ�� 1�̸� ����� �� �ֱ� ������ day==n+1�̵Ǿ����
	if (day == n+1) {
		max_val = max(max_val, val);
		return;
	}
	if (day + t[day] <=n+1)
		dfs(day + t[day], val + p[day]);
	if (day + 1 <= n+1)
		dfs(day + 1, val);

}