#include<iostream>
using namespace std;
int arr[1001];
int main()
{
	int t, i, num, cnt = 0;
	cin >> t;
	while (t--)
	{
		cin >> num;
			//�ַ��1: �Է¹����� ������ �̴�� Ǯ��.
		/*if (num > 1) {
			for (i = 2; i < num; i++)
			{
				if (num % i == 0)
					break;
			}
			if (i == num)cnt++;
		}*/

		//�ַ�� 2: �Է¹����� ũ�ٽ����� �׳� �����佺�׳׽���ü ����.

		//0�� 1�� �Ҽ��� �ƴϹǷ� 1������ üũ
		arr[0] = 1, arr[1] = 1;
		for (int i = 2; i < 1001; i++)
		{
			for (int j = i * i; j < 1001; j += i)
			{
				//�Ҽ��� �ƴ� ��� üũ
				 arr[j] = 1;
			}
		}
		if (arr[num] == 0)cnt++;
	}
	cout << cnt << endl;
	return 0;
}