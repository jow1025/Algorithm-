#include<iostream>
#include<algorithm>
using namespace std;
int map[501];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w, cnt = 0;
	int a, b;
	cin >> h >> w;
	for (int i = 0; i < w; i++) 
		cin >> map[i];

	for (int i = 1; i < w - 1; i++) {
		a = 0, b = 0;
		for (int j = 0; j < i; j++) {
			a = max(a, map[j]);
		}
		for (int j = w - 1; j > i; j--) {
			b = max(b, map[j]);
		}
		if (min(a, b) - map[i] < 0)continue;
		cnt += min(a, b) - map[i];
		
	}
	cout<<cnt<<endl;
	return 0;
}