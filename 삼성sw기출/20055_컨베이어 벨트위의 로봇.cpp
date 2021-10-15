#include<iostream>
#include<deque>
using namespace std;
deque<int>belt_power;
deque<int>robot;
int n, k, ans;
int main()
{
	int power;
	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++) {
		cin >> power;
		belt_power.push_back(power);
	}
	for(int i=0;i<n;i++)
		robot.push_back(0);

	while (1) {
		int cnt = 0;
		for (int i = 0; i < belt_power.size(); i++) {
			if (belt_power[i] == 0)
				cnt++;
		}
		if (cnt >= k) {
			break;
		}
		ans++;

		//��Ʈ ȸ��
		belt_power.push_front(belt_power.back());
		belt_power.pop_back();



		//�κ��� ȸ���ؾ��ϴµ�,�򰥸��°���.. �κ��� ���� ù���̽���...��� �����Ұ�����
		//�κ��� 0~n-1������ N���� ��Ʈ���� ������ ������
		//�κ��� 2N���� ĭ�� �ѹ��� �鸦�� �ִµ�.. �̰� ��� ǥ��? => Ʋ��. 2n�� �ƴ� nĭ���� ����
		//������ �ʿ䰡����..�κ��� ������ ȸ���� 0~n-1���̿����� �����
		//�׷��� ������ ó���� �κ����� 2*n��ŭ false�� ä���µ�, �׳� n��ŭ�� false�� ä������!!

		//�κ� ���� �Ȱ��� ��Ʈó�� ȸ��
		//�迭/ť�� �ص��Ǳ��ҵ�,, n=3�� �� �κ� ȸ�� �� [0][1][0]�϶� [0][0][1]�� �ǹǷ� �� ���� 1�� �������Ѿ��� 
		robot.push_front(robot.back());
		robot.pop_back();

		if (robot[n - 1] == 1)robot[n - 1] = 0;
		//���� �κ��� �̵���Ŵ(n=3�϶� �κ��� robot[0],robot[1],robot[2]������ ��ġ��)
		//n=3�� �� 0->1, 1->2�ΰ��� �� ���̽� �ۿ� �����Ƿ� �̸� �̿��� for������

		//�κ� 
		for (int i = n - 2; i >= 0; i--) {
			//�����ڸ��� �κ��� �ְ� ����ĭ ��������>=1�̰� �κ��� ������ ����
			if (robot[i] == 1) {
				if (belt_power[i + 1] >= 1 && robot[i + 1] == false) {
					belt_power[i + 1]--;
					robot[i] = 0;
					//����ĭ�� ����ĭ�̳Ŀ� ���� 0�������� 1������
					if (i + 1 == n - 1)robot[i + 1] = 0;
					else robot[i + 1] = 1;	
				}
			}
		}

		//�κ� �ø���
		if (belt_power[0] >= 1) {
			if (robot[0] == 0) {
				robot[0] = 1;
				belt_power[0]--;
			}
		}
		
	}
	cout << ans << endl;
}