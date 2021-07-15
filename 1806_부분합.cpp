#include<iostream>
#include<algorithm>
using namespace std;
int arr[100000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	int left = 0, high = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int sum = arr[0];//5
	int res = 1000000001;
	while (left <= high && high < n) {
		if (sum < s) {
			sum += arr[++high];
		}
		else if (sum >= s) {
			res = min(res, high - left + 1);
			sum -= arr[left++];
			if (left > high) {
				high = left;
				sum = arr[left];
			}
		}
	}
	if (res == 1000000001) {
		cout << 0 << endl;
	}
	else cout << res << endl;
	return 0;
}