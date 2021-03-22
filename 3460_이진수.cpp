#include<iostream>
using namespace std;
int main()
{
	int t, n, cnt;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n;
		cnt = 0;
		while (n != 0) {
			if (n % 2 == 1)cout << cnt << " ";
			cnt++;
			n /= 2;
		}
		cout << '\n';
	}
	return 0;
}