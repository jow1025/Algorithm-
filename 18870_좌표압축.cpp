
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<deque>
#include<vector>
#include<queue>
#define endl '\n'
using namespace std;
vector<int>v1;
vector<int>v2;
int main()
{
	int n;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v1.push_back(num);
		v2.push_back(num);
	}
	sort(v2.begin(), v2.end());
	//unique함수 반환값은 쓰레기값 첫 인덱스 가르침
	//그 인덱스~end()까지 erase하면 중복 제거됨
	
	v2.erase(unique(v2.begin(), v2.end()),v2.end());
	
	for (int i = 0; i < n; i++) {
		cout << lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin()<<" ";
	}
	
}