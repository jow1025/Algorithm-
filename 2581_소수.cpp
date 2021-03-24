#include<iostream>
using namespace std;
int arr[10001];
int main()
{
	int m, n, sum = 0;
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i <= 10001; i++)
		for (int j = i * i; j <= 10001; j += i)
		{
			if (arr[j] == 1)continue;
			arr[j] = 1;
		}
	cin >> m >> n;
	int min = 10001;
	for (int i = m; i <= n; i++) {
		if (arr[i] == 0)
		{
			sum += i;
			if (min > i)min = i;
		}
	}
	if (sum) {
		cout << sum << endl;
		cout << min << endl;
	}
	else
		cout << -1 << endl;

	return 0;
}