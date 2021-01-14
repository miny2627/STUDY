#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 501

using namespace std;

int arr[MAX][MAX];
long long dp[MAX][MAX];

int n, m;

// right, left, down, up
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int dfs(int x, int y) {
	if (x == m - 1 && y == n - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y]; // visited

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		// next X, Y
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
			if (arr[x][y] > arr[nx][ny]) {
				dp[x][y] += dfs(nx, ny);
			}
		}
	}
	return dp[x][y];
}

int main() {
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			dp[i][j] = -1; // not visited
		}
	}
	cout << dfs(0, 0);

	return 0;
}
