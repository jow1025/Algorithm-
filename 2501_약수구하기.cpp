#include <iostream>
using namespace std;
int main()
{
	int n, k, i, c = 0;
	cin >> n >> k;

	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
			c++;
		if (c == k)
			break;
	}
	if (i <= n)
		cout << i << endl;
	else
		cout << 0 << endl;
}