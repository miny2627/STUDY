#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[1001][1001];
int dp[1001][1001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int cnt = max(dp[i - 1][j - 1], max(dp[i][j - 1], dp[i - 1][j]));
			dp[i][j] = arr[i][j] + cnt;
		}
	}

	cout << dp[n][m];

	return 0;
}
