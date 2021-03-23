#include<iostream>
#include<algorithm>
bool comp(const int a, const int b)
{
	return a > b;
}
using namespace std;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	int arr[10];
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 10; j++)
			cin >> arr[j];
		sort(arr, arr + 10, comp);
		cout << arr[2] << '\n';
	}
	return 0;
}