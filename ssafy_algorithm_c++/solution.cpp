#include <iostream>
#include <vector>

using namespace std;

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

// 정답
unsigned int min_dist = 100000;

void dfs(int sr, int sc, int milk, int dist, vector<vector<int>> vill, int n_size) {
	// 탈출 조건
	if (milk == 0 || dist >= min_dist) {
		if (min_dist > dist) {
			min_dist = dist;
			return;
		}
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		int nr = sr + dr[i];
		int nc = sc + dc[i];
		// 좌표를 벗어나지 않았을 경우만 진행
		if (0 <= nr && nr < n_size && 0 <= nc && nc < n_size)
		{
			// 1 = 우유 판매
			if (vill[nr][nc] == 1) {
				// 2 = 이미 지나간 곳으로 처리
				vill[nr][nc] = 2;
				dfs(nr, nc, milk - 1, dist + 1, vill, n_size );
				vill[nr][nc] = 1;
			}
			// 0 = 일반 도로
			else if (vill[nr][nc] == 0) {
				vill[nr][nc] = 2;
				dfs(nr, nc, milk, dist + 1, vill, n_size);
				vill[nr][nc] = 0;
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		min_dist = 100000;
		// 데이터 입력
		int N, M;
		cin >> N >> M;
		// 2차원 배열 (좌표)
		vector<vector <int>> vill;

		for (int i = 0; i < N; i++)
		{
			vector<int> sample;
			for (int j = 0; j < N; j++)
			{
				int x;
				cin >> x;
				sample.push_back(x);
			}
			vill.push_back(sample);
		}

		dfs(0, 0, M, 0, vill, N);

		cout << '#' << t << ' ' << min_dist << endl;
	}
}

//#include <algorithm>
//#include <queue>
//#include <stack>
//#include <tuple>
// dfs
//stack<tuple<int, int, int>> st;
//st.push(make_tuple(0, 0, m));
//while (!st.empty()) {
//	int x = get<0>(st.top());
//	int	y = get<1>(st.top());
//	int milk = get<2>(st.top());
//	st.pop();
//	for (int i = 0; i < 4; i++)
//	{	
//		int px = x + dx[i];
//		int py = y + dy[i];
//		// 좌표를 벗어나지 않았을 경우만
//		if (0 <= px < n && 0 <= py < n)
//		{
//			if (v[px][py] == 1) {
//				v[px][py] = 2;
//				st.push(make_tuple(x + dx[i], y + dy[i], milk-1));
//			}
//			else {
//				v[px][py] = 2;
//				st.push(make_tuple(x + dx[i], y + dy[i], milk));
//			}
//		}
//	}
//}