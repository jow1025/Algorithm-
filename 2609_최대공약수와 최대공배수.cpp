#include<iostream>
using namespace std;
int GCD(int a, int b);
int main()
{
	int n, m;
	cin >> n >> m;
	//최대공약수->유클리드 호제법
	//최대공배수-> (n*m)/최대공약수
	int gcd = GCD(n, m);
	cout << gcd << endl;
	cout << (n * m) / gcd << endl;
	return 0;
}
int GCD(int a, int b)
{
	int c;
	while (b)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}
