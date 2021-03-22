#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n,num;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cout << v[0] << " " << v[n - 1] << '\n';
	return 0;
}