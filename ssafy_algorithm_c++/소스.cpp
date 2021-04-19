#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool SortSecCol(const vector<int>& v1, const vector<int>& v2)
{
	return v1[1] < v2[1];
}

int main() {
	// 
	int t;
	cin >> t;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n+1, vector<int>(3));

	int m_arr[10001] = { 0, };
	for (int i = 0; i < n; i++)
	{
		int si, ei, ci;
		cin >> si >> ei >> ci;

		v[i][0] += si;
		v[i][1] += ei;
		v[i][2] += ci;
		// cout << v[i].back() << ' ';
	}
	sort(v.begin(), v.end(), SortSecCol);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}