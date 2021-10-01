
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

	//2사분면-> 1사분면-> 3사분면->4사분면 순 체크
	//범위체크할 때 r,c의 시작, 끝 범위 둘다 지정해야함
	//
	if (r < y + len && c < x + len && r >= y && c >= x) {
		//2사분면(시작이 0,0이므로)
		func(len / 2, y, x);
		//1사분면
		func(len / 2, y, x + len / 2);
		//3사분면
		func(len / 2, y + len / 2, x);
		//4사분면
		func(len / 2, y + len / 2, x + len / 2);
	}
	//끝일까?
	//재귀로 돌렸을 때 좌표계에 r,c가 없을 때 좌표 계산.

	//결과적으로 1,2,3,4..식으로 카운트 세고 r,c좌표에 도착시 +1해주지않고 출력
	//len*len씩 돌리면 됨
	else ans += len * len;
	
}