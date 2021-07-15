#include<iostream>
using namespace std;
int arr[10001];
int main()
{


	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	int left = 0, right = 0, sum = arr[0];
	while (left <= right && right < n) {
		if (sum < m) {
			sum += arr[++right];
		}
		else if (sum >= m) {
			if (sum == m)cnt++;
			sum -= arr[left++];

			//백준 1806번도 그렇고 굉장히 주의해야함
			//예제2번 케이스를 실행해보면
			//1 2 3 4 2 5 3 1 1 2 에서 '5'값에서 a=b가됨
			//아래 코드가 없으면 left가 >high되므로 반복문 탈출됨
			
			//1806번 코드는 아래 코드없어도 잘 돌아가던데
			//실행디버그는 똑같던데 왜 1806번은 잘 돌아가는지 이해안됨
			if (left > right) {
				right = left;
				sum = arr[left];
			}
		}
	}
	cout << cnt << endl;
	return 0;
}