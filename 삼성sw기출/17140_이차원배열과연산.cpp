#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int r, c, k;
int map[101][101];
int num[101];
int ans;

int main()
{
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> map[i][j];

	if (map[r][c] == k) {
		cout << 0 << endl;
		return 0;
	}
	int row = 3;
	int col = 3;
	
	//vector<pair<int, int>>v;
	while (1) {
		vector<int>size;
		if (ans > 100) {
			cout << -1 << endl;
				return 0;
		}
		if (map[r][c] == k) {
			cout << ans << endl;
			return 0;
		}
		if (row >= col) {
			/*�� ���ο� vector�ʱ�ȭ�� num�迭 �ʱ�ȭ�ϸ�ȵ�*/
			for (int i = 1; i <= row; i++) {
				vector<pair<int, int>>v;
				memset(num, 0, sizeof(num));
				for (int j = 1; j <= col; j++) {
					num[map[i][j]]++;
				}
				for (int start = 1; start <= 100; start++) {
					if (num[start])
						//����-��
						v.push_back({ num[start],start });
				}
				//����
				sort(v.begin(), v.end());
				//0���� �� ä������ �����ϸ� ��
				//���ڸ� Ǫ���ϰ� 0�� ���ص���(���ڸ� ä���� �̹� �������� 0����ä�����⶧��)
				for (int j = 1; j <= col; j++) {
					map[i][j] = 0;
				}
				int idx = 1;
				for (int j = 0; j < v.size(); j++) {
					map[i][idx] = v[j].second;
					idx++;
					map[i][idx] = v[j].first;
					idx++;
				}
				idx--;
				//���� ���̸� Ǫ���� �� ���� �� ���� ���̰� �� ���Ǳ���
				size.push_back(idx);
			}
			sort(size.begin(), size.end());
			//�� �߿� ���� ū ����
			col = size[size.size() - 1];
		}
		else {
			/*�� ���ο� vector�ʱ�ȭ�� num�迭 �ʱ�ȭ�ϸ�ȵ�*/
			for (int i = 1; i <= col; i++) {
				vector<pair<int, int>>v;
				memset(num, 0, sizeof(num));
				for (int j = 1; j <= row; j++) {
					num[map[j][i]]++;
				}
				for (int start = 1; start <= 100; start++) {
					if (num[start])
						//����-��
						v.push_back({ num[start],start });
				}
				//����
				sort(v.begin(), v.end());
				//0���� �� ä������ �����ϸ� ��
				//���ڸ� Ǫ���ϰ� 0�� ���ص���(���ڸ� ä���� �̹� �������� 0����ä�����⶧��)
				for (int j = 1; j <= row; j++) {
					map[j][i] = 0;
				}
				int idx = 1;
				for (int j = 0; j < v.size(); j++) {
					map[idx][i] = v[j].second;
					idx++;
					map[idx][i] = v[j].first;
					idx++;
				}
				idx--;
				//���� ���̸� Ǫ���� �� ���� �� ���� ���̰� �� ���Ǳ���
				size.push_back(idx);
			}
			sort(size.begin(), size.end());
			row = size[size.size() - 1];
		}
		ans++;
	}
}