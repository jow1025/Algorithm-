#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
string map[51];
int func();
int main()
{
	int res = 1;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> map[i];
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			//<-> ����/������ �ٲٰ� �ִ� ���� ���� Ȯ��
			if(map[i][j-1]!=map[i][j])
				swap(map[i][j - 1], map[i][j]);
			int val1 = func();
			res = max(val1, res);
			//���󺹱�
			swap(map[i][j - 1], map[i][j]);

			//��/�� �ٲٰ� �ִ� ���� ���� Ȯ��
			if(map[j-1][i]!=map[i][j])
				swap(map[j - 1][i], map[j][i]);
			int val2=func();
			res = max(val2, res);
			swap(map[j - 1][i], map[j][i]);
			
		}
	}
	cout <<res << endl;
	return 0;
}
int func()
{
	int val = 1;
	//�� ��, �����¿츦 �Ǵ��ؾ���

	//�� ��
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (map[i][j - 1] == map[i][j])
				cnt++;
			else {
				val = max(val, cnt);
				cnt = 1;
			}
		}
		val = max(val, cnt);
	}
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (map[j - 1][i] == map[j][i])
				cnt++;
			else {
				val = max(val, cnt);
				cnt = 1;
			}
		}
		val = max(val, cnt);
	}
	return val;
}