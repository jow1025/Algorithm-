#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
int max_val = -1000000001;
int min_val = 1000000001;
int n;
int arr[11];
int op[4];
void dfs(int val, int num_cnt);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> op[0] >> op[1] >> op[2] >> op[3];
	dfs(arr[0],1);
	cout << max_val << endl << min_val << endl;
	return 0;
}
void dfs(int val, int num_cnt)
{
	if (num_cnt == n) {
		max_val = max(max_val, val);
		min_val = min(min_val, val);
		return;
	}
	for (int i = 0; i < 4; i++) {
		//연산자가 있을 때
		if (op[i]) {
			// + - * /순
			if (i == 0) {
				op[i]--;
				dfs(val +arr[num_cnt] , num_cnt + 1);
				op[i]++;
			}
			if (i == 1) {
				op[i]--;
				dfs(val - arr[num_cnt], num_cnt + 1);
				op[i]++;
			}
			if (i == 2) {
				op[i]--;
				dfs(val * arr[num_cnt], num_cnt + 1);
				op[i]++;
			}
			if (i == 3) {
				op[i]--;
				dfs(val / arr[num_cnt], num_cnt + 1);
				op[i]++;
			}
		}
		
	}
}