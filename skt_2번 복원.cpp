
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int max_val = 0;
vector<int>input;
vector<int>v;
int visited[201];
void dfs(int cnt,int size);
int main()
{
	//어떤 사람들의 키가 사람들 순서대로 나열되어있을 떄
	//|arr[0]-arr[1]|+arr[1]-arr[2]| .....의 합이 최대가 될 때 그 키
	//n>=2, <=8, 키는 200이하
	//사람의 키는 중복되지 않고 똑같은 키는 한번만 입력됨
	//ex) [1,2,3,4,6]일 때 답 13임
	
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		input.push_back(num);
	}
	dfs(0,input.size());
	cout << max_val << endl;
	return 0;
}
void dfs(int cnt, int size)
{
	int sum = 0;

	if (cnt == size) {
		for (int i = 0; i < cnt - 1; i++) {
			sum += abs(v[i] - v[i + 1]);

		}
		max_val = max(sum, max_val);
		if (sum== 13) {
			for (int i = 0; i < cnt; i++) {
				cout << v[i] << " ";
			}cout << endl;
		}
		return;
	}
	for (int i = 0; i < size; i++) {
		if (!visited[input[i]]) {
			visited[input[i]] = 1;
			v.push_back(input[i]);
			dfs(cnt + 1, size);
			v.pop_back();
			visited[input[i]] = 0;
		}
	}
}
