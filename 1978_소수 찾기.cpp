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
			//솔루션1: 입력범위가 작으면 이대로 풀자.
		/*if (num > 1) {
			for (i = 2; i < num; i++)
			{
				if (num % i == 0)
					break;
			}
			if (i == num)cnt++;
		}*/

		//솔루션 2: 입력범위가 크다싶으면 그냥 에라토스테네스의체 쓰자.

		//0과 1은 소수가 아니므로 1값으로 체크
		arr[0] = 1, arr[1] = 1;
		for (int i = 2; i < 1001; i++)
		{
			for (int j = i * i; j < 1001; j += i)
			{
				//소수가 아닌 경우 체크
				 arr[j] = 1;
			}
		}
		if (arr[num] == 0)cnt++;
	}
	cout << cnt << endl;
	return 0;
}