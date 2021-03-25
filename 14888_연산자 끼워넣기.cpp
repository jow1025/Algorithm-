#include<iostream>
#include<algorithm>
using namespace std;
int min_val = 1000000001;
int max_val = -1000000001;
int arr[12];
int op[4];
int n;
void func(int num, int cnt);
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];

	int num = arr[0];
	func(num, 1);
	cout << max_val << endl << min_val << endl;

}
void func(int num, int cnt)
{
	//숫자를 다 썼으면
	if (cnt == n)
	{
		max_val = max(max_val, num);
		min_val = min(min_val, num);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (op[i]) {
			if (i == 0)
			{
				op[i]--;
				func(num + arr[cnt], cnt + 1);
				op[i]++;
			}
			if (i == 1)
			{
				op[i]--;
				func(num - arr[cnt], cnt + 1);
				op[i]++;
			}
			if (i == 2)
			{
				op[i]--;
				func(num * arr[cnt], cnt + 1);
				op[i]++;
			}
			if (i == 3)
			{
				op[i]--;
				func(num / arr[cnt], cnt + 1);
				op[i]++;
			}
		}
	}
}