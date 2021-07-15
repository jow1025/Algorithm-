#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long s;
	long long start = 0;
	int res = 0;
	cin >> s;
	for (int i = 1; ; i++) {
		if (start > s)
		{
			res--;
			break;
		}
		start += i;
		res++;
	}
	cout << res << endl;
	return 0;
}