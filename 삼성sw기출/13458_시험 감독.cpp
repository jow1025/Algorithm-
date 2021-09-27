#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000001];
long long ans;
int main()
{
	int n, a, b;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> a >> b;
	for (int i = 1; i <= n; i++) {
		//예제입력1의 결과를 보니 부감독관은 없어도 됨
		//총감독은 무조건 1명이니 -a해주고 시작
		arr[i] = arr[i] - a;
		ans++;
		if (arr[i] <= 0)continue;

		if (arr[i] % b == 0)ans += arr[i] / b;
		else ans +=(arr[i] / b + 1);

	}
	cout << ans << endl;
}