#include<iostream>
#include<algorithm>
using namespace std;
int arr[9];
int main()
{
	int i,j, sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	//���տ��� 2���� ������ Ű�� �� ���� 100�� �� �� 2�� ����
	// Ű�� 100�� ���������Ƿ� 2�� ���� �� �������� Ű�� -1 or 101�� ����
	for ( i = 0; i < 9; i++)
	{
		for ( j = 0; j < 9; j++)
		{
			if (i != j)
			{
				if (sum - arr[i] - arr[j] == 100)
				{
					arr[i] = 101, arr[j] = 101;
					//must
					break;
				}
			}
		}
		//must
		if (arr[i] == 101 && arr[j] == 101)break;
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 7; i++)
		cout << arr[i] << endl;
	return 0;
}