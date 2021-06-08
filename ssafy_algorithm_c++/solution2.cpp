#include <iostream>
#include <time.h>

using namespace std;

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

// ����
unsigned int min_dist = 100000;

void dfs(int sr, int sc, int milk, int dist, int vill[][15], int n_size) {
	// Ż�� ����
	if (milk == 0 || dist >= min_dist) {
		if (min_dist > dist) {
			min_dist = dist;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nr = sr + dr[i];
		int nc = sc + dc[i];
		// ��ǥ�� ����� �ʾ��� ��츸 ����
		if (0 <= nr && nr < n_size && 0 <= nc && nc < n_size) {
			// 1 = ���� �Ǹ�
			if (vill[nr][nc] == 1) {
				// 2 = �̹� ������ ������ ó��
				vill[nr][nc] = 2;
				dfs(nr, nc, milk - 1, dist + 1, vill, n_size);
				vill[nr][nc] = 1;
			}
			// 0 = �Ϲ� ����
			else if (vill[nr][nc] == 0) {
				vill[nr][nc] = 2;
				dfs(nr, nc, milk, dist + 1, vill, n_size);
				vill[nr][nc] = 0;
			}
		}
	}
}

int main() {
	clock_t start, mid, end;
	int tc;
	cin >> tc;

	start = clock();
	cout << start << endl;

	for (int t = 1; t <= tc; t++) {
		min_dist = 100000;
		// ������ �Է�
		int N, M;
		cin >> N >> M;
		// 2���� �迭 (��ǥ)
		int vill[15][15] = { 0, };

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int x;
				cin >> x;
				vill[i][j] = x;
			}
		}

		mid = clock();
		cout << mid << endl;

		dfs(0, 0, M, 0, vill, N);
		cout << '#' << t << ' ' << min_dist << endl;

		end = clock();
		cout << end << endl;
		cout << "�ɸ� �ð�: " << (double)(end - start) << endl;
	}

}






