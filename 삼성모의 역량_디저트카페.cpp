#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define endl '\n'
int t, n, map[20][20], visited[101];
int dx[4] = { -1,1,1,-1 };
int dy[4] = { 1,1,-1,-1 };
//좌하,우하,우상,좌상
int ans;
//현재 위치, dfs를 돌고나서 
void dfs(int y, int x,int target_y,int target_x, int line,int cake);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;

	for (int cnt = 1; cnt <= t; cnt++) {
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		ans = -1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
					if (j == 0)continue;//1열 연산 제외
					if (j == n - 1)continue;//n-1열 연산 제외
					if (i == n - 2)continue;//n-2행 연산 제외
					if (i == n - 1)continue;//n-1행 연산 제외
				//디저트 가게 중복 체크
				visited[map[i][j]] = 1;
				//line이 3이 되면 사각형
				dfs(i, j,i,j,0,1);
				visited[map[i][j]] = 0;
			}
		}


		cout << '#' << cnt << " " << ans<<endl;
	}
	return 0;
}
void dfs(int y, int x, int target_y, int target_x, int line, int cake)
{

	/*if (line > 3)
		return;*/

	//target 위치와 y,x 가 같을 때를 점검(이 코드없으면 y,x좌표에서 시작하는 사각형이 아닌 그냥 사각형 여부확인)
	//아래 if문으로 사각형 체크하는 코드가 ny,nx변수 명 선언 보다 뒤에 있어야함(앞에 선언되었다면 변3개 상태에서 최초 지점으로 못들어감)
	//line==3의 의미는 꼭짓점의 갯수가4개(0,1,2,3) 라는뜻
	
	int ny = y + dy[line];
	int nx = x + dx[line];
	if (line == 3) {
		if (ny == target_y && nx == target_x) {
			ans = max(ans, cake);
			return;
		}
	}

	//탐색
	
		if (ny >= 0 && nx >= 0 && ny < n && nx < n&&!visited[map[ny][nx]]) {
			visited[map[ny][nx]] = 1;
			//가던 방향일 때는 line은 그대로+ line 변수값 0~4까지 각각 방향을 나타내기도함
			dfs(ny, nx, target_y, target_x, line, cake + 1);
			//2개의 dfs문을 line<3조건문 안에 다 넣으면 안됨
			//직진했을 때는 line변수값 변화없이 탐색을 계속 진행하는 것이고 꺾을 때는 line++하면서 진행하는것
			
			if (line < 3) {
				//dfs(ny, nx, target_y, target_x, line, cake + 1);
				//방향을 꺾을 때	
				dfs(ny, nx, target_y, target_x, line + 1, cake + 1);
				
			}
			visited[map[ny][nx]] = 0;
		}
		
}
