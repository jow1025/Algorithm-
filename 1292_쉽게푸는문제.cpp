#include<iostream>
using namespace std;
int arr[1001];
int main()
{
	int a, b, sum = 0, k = 0;
	cin >> a >> b;
	int i, j = 0;
	for (i=1; i <=1000; i++)
	{
		for (j=1; j <=i; j++)
		{
			arr[k] = i;
			if (k >= 1000)break;
			k++;
		}
	}
	for (int i=a-1;i<b;i++)
	{
		sum += arr[i];
	}
	cout << sum << endl;
	return 0;
}