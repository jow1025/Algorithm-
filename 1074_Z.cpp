
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define endl '\n'
using namespace std;
int ans,r, c;
void func(int len , int y, int x);
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n >> r >> c;
	func(pow(2, n), 0, 0);

}
void func(int len, int y, int x)
{

	if (y == r && x == c) {
		cout << ans << endl;
		return;
	}

	//2��и�-> 1��и�-> 3��и�->4��и� �� üũ
	//����üũ�� �� r,c�� ����, �� ���� �Ѵ� �����ؾ���
	//
	if (r < y + len && c < x + len && r >= y && c >= x) {
		//2��и�(������ 0,0�̹Ƿ�)
		func(len / 2, y, x);
		//1��и�
		func(len / 2, y, x + len / 2);
		//3��и�
		func(len / 2, y + len / 2, x);
		//4��и�
		func(len / 2, y + len / 2, x + len / 2);
	}
	//���ϱ�?
	//��ͷ� ������ �� ��ǥ�迡 r,c�� ���� �� ��ǥ ���.

	//��������� 1,2,3,4..������ ī��Ʈ ���� r,c��ǥ�� ������ +1�������ʰ� ���
	//len*len�� ������ ��
	else ans += len * len;
	
}