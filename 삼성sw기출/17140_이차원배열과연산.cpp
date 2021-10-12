#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int r, c, k;
int map[101][101];
int num[101];
int ans;

int main()
{
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> map[i][j];

	if (map[r][c] == k) {
		cout << 0 << endl;
		return 0;
	}
	int row = 3;
	int col = 3;
	
	//vector<pair<int, int>>v;
	while (1) {
		vector<int>size;
		if (ans > 100) {
			cout << -1 << endl;
				return 0;
		}
		if (map[r][c] == k) {
			cout << ans << endl;
			return 0;
		}
		if (row >= col) {
			/*이 라인에 vector초기화와 num배열 초기화하면안됨*/
			for (int i = 1; i <= row; i++) {
				vector<pair<int, int>>v;
				memset(num, 0, sizeof(num));
				for (int j = 1; j <= col; j++) {
					num[map[i][j]]++;
				}
				for (int start = 1; start <= 100; start++) {
					if (num[start])
						//갯수-수
						v.push_back({ num[start],start });
				}
				//정렬
				sort(v.begin(), v.end());
				//0으로 다 채워놓고 시작하면 됨
				//숫자만 푸시하고 0은 안해도됨(숫자만 채워도 이미 나머지는 0으로채워지기때문)
				for (int j = 1; j <= col; j++) {
					map[i][j] = 0;
				}
				int idx = 1;
				for (int j = 0; j < v.size(); j++) {
					map[i][idx] = v[j].second;
					idx++;
					map[i][idx] = v[j].first;
					idx++;
				}
				idx--;
				//열의 길이를 푸쉬한 뒤 가장 긴 열의 길이가 새 열의길이
				size.push_back(idx);
			}
			sort(size.begin(), size.end());
			//열 중에 가장 큰 길이
			col = size[size.size() - 1];
		}
		else {
			/*이 라인에 vector초기화와 num배열 초기화하면안됨*/
			for (int i = 1; i <= col; i++) {
				vector<pair<int, int>>v;
				memset(num, 0, sizeof(num));
				for (int j = 1; j <= row; j++) {
					num[map[j][i]]++;
				}
				for (int start = 1; start <= 100; start++) {
					if (num[start])
						//갯수-수
						v.push_back({ num[start],start });
				}
				//정렬
				sort(v.begin(), v.end());
				//0으로 다 채워놓고 시작하면 됨
				//숫자만 푸시하고 0은 안해도됨(숫자만 채워도 이미 나머지는 0으로채워지기때문)
				for (int j = 1; j <= row; j++) {
					map[j][i] = 0;
				}
				int idx = 1;
				for (int j = 0; j < v.size(); j++) {
					map[idx][i] = v[j].second;
					idx++;
					map[idx][i] = v[j].first;
					idx++;
				}
				idx--;
				//열의 길이를 푸쉬한 뒤 가장 긴 열의 길이가 새 열의길이
				size.push_back(idx);
			}
			sort(size.begin(), size.end());
			row = size[size.size() - 1];
		}
		ans++;
	}
}