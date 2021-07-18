
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<deque>
#include<vector>
#include<queue>

#define endl '\n'
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	priority_queue<int>q;
	int n, num; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num>0) {
			q.push(num);
		}
		else {
			if (q.empty()) {
				cout << 0 << endl;
			}
			else {
				cout << q.top() << endl;
				q.pop();
			}
		}
	}
}
