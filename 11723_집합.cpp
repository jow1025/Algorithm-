
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<deque>
#include<vector>
#include<queue>
#define endl '\n'
using namespace std;
int visited[21];
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int m, num;
	string s;
	cin >> m;
	while (m--) {
		cin >> s;
		if (s == "add") {
			cin >> num;
			visited[num] = 1;
		}
		else if (s == "check") {
			cin >> num;
			if (visited[num])cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (s == "remove") {
			cin >> num;
			visited[num] = 0;
		}
		else if (s == "toggle") {
			cin >> num;
			if (!visited[num])
				visited[num] = 1;
			else visited[num] = 0;
		}
		else if (s == "all") {
			for (int i = 1; i <= 20; i++)
				visited[i] = 1;
		}
		else if (s == "empty") {
			for (int i = 1; i <= 20; i++)
				visited[i] = 0;
		}
	}
}
