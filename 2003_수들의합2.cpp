#include<iostream>
using namespace std;
int arr[10001];
int main()
{


	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	int left = 0, right = 0, sum = arr[0];
	while (left <= right && right < n) {
		if (sum < m) {
			sum += arr[++right];
		}
		else if (sum >= m) {
			if (sum == m)cnt++;
			sum -= arr[left++];

			//���� 1806���� �׷��� ������ �����ؾ���
			//����2�� ���̽��� �����غ���
			//1 2 3 4 2 5 3 1 1 2 ���� '5'������ a=b����
			//�Ʒ� �ڵ尡 ������ left�� >high�ǹǷ� �ݺ��� Ż���
			
			//1806�� �ڵ�� �Ʒ� �ڵ��� �� ���ư�����
			//�������״� �Ȱ����� �� 1806���� �� ���ư����� ���ؾȵ�
			if (left > right) {
				right = left;
				sum = arr[left];
			}
		}
	}
	cout << cnt << endl;
	return 0;
}