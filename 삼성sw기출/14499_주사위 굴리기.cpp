#include<iostream>
using namespace std;
int map[21][21];
int n, m, x, y, k, order;
//������ ���� �ֻ��� ��������� ����(1��=����, 3��=����, 4��:���� ���)
int dice[7];
int temp[7];
int main()
{
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

		}
	}

	for (int i = 0; i < k; i++) {
		cin >> order;
		/* ����
		1. ������ ����� �ȵ�, ����� �ƹ��� ���x
		2. �� ��ǥ�� �����ϰ� �ֻ��� ��ȣ�������ؾ���

		//1,2���� �����ϸ� map[y][x]�� dice[6](�Ʒ���)�� �����
		//�Ź� ������ �� �ֻ��� ���� �������Ѿ���(order���� ���� �ֻ��� ����� ������ä�� ����������)

		*/
		if (order == 1) {
		//������ ���� ���� �����Ͽ� ����1����
			if (x + 1 < m) {
				x = x + 1;
			//���� ����� �ֻ��� ���¸� �״�� �����ؾ���
			//���ʵ������� �����̸� 2,5�� �ȿ�����
			//6�� �Ʒ����̹Ƿ� �����ӿ� ����
				
				temp[4] = dice[4];
				temp[1] = dice[1];
				temp[3] = dice[3];
				temp[6] = dice[6];

				//������ ���� ǥ��
				dice[4] = temp[6];
				dice[1] = temp[4];
				dice[3] = temp[1];
				dice[6] = temp[3];
			
				if (map[y][x] == 0) {
					map[y][x] = dice[6];
				}
				else {
					dice[6] = map[y][x];
					map[y][x] = 0;
				}
				cout << dice[1] << endl;
			}
		}
		else if (order == 2) {
			if (x - 1 >= 0) {
				x = x - 1;
				temp[4] = dice[4];
				temp[1] = dice[1];
				temp[3] = dice[3];
				temp[6] = dice[6];

				//������ ���� ǥ��
				dice[4] = temp[1];
				dice[1] = temp[3];
				dice[3] = temp[6];
				dice[6] = temp[4];
				if (map[y][x] == 0) {
					map[y][x] = dice[6];
				}
				else {
					dice[6] = map[y][x];
					map[y][x] = 0;
				}
				cout << dice[1] << endl;
			}
		}
		else if (order == 3) {
			if (y - 1 >= 0) {
				y = y - 1;
				temp[2] = dice[2];
				temp[1] = dice[1];
				temp[5] = dice[5];
				temp[6] = dice[6];

				//������ ���� ǥ��
				dice[2] = temp[1];
				dice[1] = temp[5];
				dice[5] = temp[6];
				dice[6] = temp[2];
				if (map[y][x] == 0) {
					map[y][x] = dice[6];
				}
				else {
					dice[6] = map[y][x];
					map[y][x] = 0;
				}
				cout << dice[1] << endl;
			}
		}
		else if (order == 4) {
			if (y + 1 < n) {
				y = y + 1;
				temp[2] = dice[2];
				temp[1] = dice[1];
				temp[5] = dice[5];
				temp[6] = dice[6];

				//������ ���� ǥ��
				dice[2] = temp[6];
				dice[1] = temp[2];
				dice[5] = temp[1];
				dice[6] = temp[5];
				if (map[y][x] == 0) {
					map[y][x] = dice[6];
				}
				else{
					dice[6] = map[y][x];
					map[y][x] = 0;
				}
				cout << dice[1] << endl;
			}
		}
	}

}