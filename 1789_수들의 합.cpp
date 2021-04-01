#include<iostream>
using namespace std;
int main()
{
	long long S;
	cin >> S;
	int cnt = 1;
	long long start = 1;

	for (int i = 1; start != S; i++) {
		if (start >= S) {
			cnt--;
			break;
		}

		start += i + 1;
		cnt++;
	}

	cout << cnt;

}