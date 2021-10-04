
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
	//� ������� Ű�� ����� ������� �����Ǿ����� ��
	//|arr[0]-arr[1]|+arr[1]-arr[2]| .....�� ���� �ִ밡 �� �� �� Ű
	//n>=2, <=8, Ű�� 200����
	//����� Ű�� �ߺ����� �ʰ� �Ȱ��� Ű�� �ѹ��� �Էµ�
	//ex) [1,2,3,4,6]�� �� �� 13��
	
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
