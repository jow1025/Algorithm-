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

		//벨트 회전
		belt_power.push_front(belt_power.back());
		belt_power.pop_back();



		//로봇도 회전해야하는데,헷갈리는것이.. 로봇이 없는 첫케이스랑...어떻게 연산할것인지
		//로봇은 0~n-1사이의 N길이 벨트에서 무한히 움직임
		//로봇은 2N개의 칸에 한번씩 들를수 있는데.. 이걸 어떻게 표현? => 틀림. 2n이 아닌 n칸에만 존재
		//생각할 필요가없음..로봇의 생성과 회전은 0~n-1사이에서만 연산됨
		//그렇기 때문에 처음에 로봇덱을 2*n만큼 false로 채웠는데, 그냥 n만큼만 false로 채워도됨!!

		//로봇 덱도 똑같이 벨트처럼 회전
		//배열/큐로 해도되긴할듯,, n=3일 때 로봇 회전 후 [0][1][0]일때 [0][0][1]이 되므로 이 때는 1을 삭제시켜야함 
		robot.push_front(robot.back());
		robot.pop_back();

		if (robot[n - 1] == 1)robot[n - 1] = 0;
		//이제 로봇을 이동시킴(n=3일때 로봇은 robot[0],robot[1],robot[2]에서만 위치함)
		//n=3일 때 0->1, 1->2로가는 두 케이스 밖에 없으므로 이를 이용한 for문구성

		//로봇 
		for (int i = n - 2; i >= 0; i--) {
			//현재자리에 로봇이 있고 다음칸 내구도가>=1이고 로봇이 없으면 전진
			if (robot[i] == 1) {
				if (belt_power[i + 1] >= 1 && robot[i + 1] == false) {
					belt_power[i + 1]--;
					robot[i] = 0;
					//다음칸이 내림칸이냐에 따라 0으로할지 1로할지
					if (i + 1 == n - 1)robot[i + 1] = 0;
					else robot[i + 1] = 1;	
				}
			}
		}

		//로봇 올리기
		if (belt_power[0] >= 1) {
			if (robot[0] == 0) {
				robot[0] = 1;
				belt_power[0]--;
			}
		}
		
	}
	cout << ans << endl;
}