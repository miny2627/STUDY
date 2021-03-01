#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arr[25][25];
bool check[25][25];
int n;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int dfs(int x, int y) {
	int cnt = 0;
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (arr[nx][ny] == 0 || check[nx][ny]) continue;

		cnt++;
		check[nx][ny] = true;
		cnt += dfs(nx, ny);
	}
	return cnt;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && !check[i][j]) {
				ans.push_back(dfs(i, j));
			}
		}
	}
	
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << endl;
	}

	return 0;
}
