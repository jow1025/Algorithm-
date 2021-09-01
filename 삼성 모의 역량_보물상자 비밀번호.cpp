#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
int a[7];
string str;
vector <int> v;

void rotate() {
	char tmp = str[str.size() - 1];
	for (int i = str.size() - 2; i >= 0; i--) {
		str[i + 1] = str[i];
	}
	str[0] = tmp;
}//회전

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		cin >> str;
		int k = str.size() / 4;
		int cnt = k;
		int sum = 0;
		while (cnt--) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < k; j++) {
					if (str[j + (k * i)] >= 'A')
						a[j] = str[j + (k * i)] - 'A' + 10;
					else a[j] = str[j + (k * i)] - '0';
					int s = pow(16, k - j - 1);
					a[j] *= s;
					sum += a[j];
				}
				v.push_back(sum);
				sum = 0;
				memset(a, 0, sizeof(a));
			}
			rotate();
		}
		sort(v.begin(), v.end());//오름차순 정렬
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] == v[i + 1]) {
				for (int j = i + 1; j < v.size() - 1; j++)
					v[j] = v[j + 1];
				v.pop_back();
			}
		}//중복제거
		cout << "#" << test_case << ' ' << v[v.size() - K] << '\n';
		
		v.clear();
	}
	return 0;
}