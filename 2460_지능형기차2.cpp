#include<iostream>
using namespace std;
int main()
{
	int in, out;
	int max = 0, num = 0;
	//max: 기차에 가장많이 있는 사람 판별
	//num: 기차에 있는 사람의 수
	for (int i = 0; i < 10; i++) {
		cin >> out >> in;
		num = num + (in - out);
		//한번 내리고 타고 나서 사람 수 파악
		if (num > max)
			max = num;
	}
	cout << max << endl;
	return 0;
}