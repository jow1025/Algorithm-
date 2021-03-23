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
	//총합에서 2개의 난쟁이 키를 뺀 값이 100일 때 그 2명 제외
	// 키가 100을 넘지않으므로 2개 검출 한 난쟁이의 키를 -1 or 101로 조절
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