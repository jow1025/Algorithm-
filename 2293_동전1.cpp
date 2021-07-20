#include<iostream>
using namespace std;
int n, k;
int coin[101];//���� �迭
int dp[10001];//��� ����� ���� ������ dp
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[0] = 1;//0���� ����� ����Ǽ�=�ƹ������� �Ⱦ��� 1�������
	//�� �迭�� dp start
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> coin[i];

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			//dp[a]=b : a���� �����ϴ� b������ ����� ��
			//�Ź� ����
			//k=3�϶� 2���� �̿��� 3���� �������
			//1���� ������ �־�� ���� �̿�,1������ ���� ���� 2���� �����ǻ����� �̿�

			dp[j] = dp[j] + dp[j - coin[i]];
		}

	}
	cout << dp[k] << endl;
	return 0;
}