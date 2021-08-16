
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<deque>
#include<vector>
#include<queue>
#define endl '\n'
using namespace std;
int arr[1000];
int main()
{
	int sum = 0;
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		for (int j = 0; j < i; j++) {
			sum += arr[j];
		}

	}
	cout << sum << endl;
}
