#include<iostream>
using namespace std;
int GCD(int a, int b);
int main()
{
	int n, m;
	cin >> n >> m;
	//�ִ�����->��Ŭ���� ȣ����
	//�ִ�����-> (n*m)/�ִ�����
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