#include<iostream>
using namespace std;
int map[21][21];
int n, m, x, y, k, order;
//문제에 나온 주사위 전개도대로 진행(1번=맨위, 3번=동쪽, 4번:서쪽 등등)
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
		/* 조건
		1. 범위를 벗어나면 안됨, 벗어나면 아무런 출력x
		2. 맵 좌표를 관리하고 주사위 번호를관리해야함

		//1,2번만 구현하면 map[y][x]와 dice[6](아랫면)만 연산됨
		//매번 움직일 때 주사위 값을 유지시켜야함(order값에 따라 주사위 모양이 유지된채로 움직여야함)

		*/
		if (order == 1) {
		//범위에 맞을 때만 연산하여 조건1충족
			if (x + 1 < m) {
				x = x + 1;
			//전에 연산된 주사위 형태를 그대로 복붙해야함
			//왼쪽동쪽으로 움직이면 2,5는 안움직임
			//6은 아랫면이므로 움직임에 유의
				
				temp[4] = dice[4];
				temp[1] = dice[1];
				temp[3] = dice[3];
				temp[6] = dice[6];

				//움직인 것을 표현
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

				//움직인 것을 표현
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

				//움직인 것을 표현
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

				//움직인 것을 표현
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