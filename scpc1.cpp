#include<iostream>
#include<unordered_set>
#include<cstring>
using namespace std;
int t, n;
int arr[100001];
int parent[100001];
void func(int num);
void unionParent(int a, int b);
int getParent(int x);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		unordered_set<int>s;
		memset(arr, 0, sizeof(arr));
		memset(parent, 0, sizeof(parent));
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			parent[i] = i;
		}
		for (int i = 1; i <= n; i++) {
			if (arr[i] + i <= n) {
				func(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			int x=getParent(i);
			s.insert(x);
		//	cout << x << " ";
		}
		//cout << endl;
		//cout << s.size() << endl;

		cout << "Case #" <<i << endl;
		cout << s.size() << endl;
	}	
	

	return 0;

}
void func(int num)
{
	if (arr[num] + num <= n) {
		unionParent(num, num+arr[num]);
		
	}
}
void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}
int getParent(int x)
{
	if (parent[x] == x)return x;
	return parent[x] = getParent(parent[x]);
}