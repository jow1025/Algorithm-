#include<iostream>
using namespace std;
int main()
{
	int in, out;
	int max = 0, num = 0;
	//max: ������ ���帹�� �ִ� ��� �Ǻ�
	//num: ������ �ִ� ����� ��
	for (int i = 0; i < 10; i++) {
		cin >> out >> in;
		num = num + (in - out);
		//�ѹ� ������ Ÿ�� ���� ��� �� �ľ�
		if (num > max)
			max = num;
	}
	cout << max << endl;
	return 0;
}