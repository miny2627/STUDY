#include <iostream>
#include <algorithm>
#define MAX 10001

using namespace std;

int main() {
	int n, k;
	int dp[MAX] = {0,};
	int coin[101];

	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		dp[i] = MAX;
	}

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
		for (int j = coin[i]; j <= k; j++) {
			// dp[j - coin[i]] => coin[i]를 더해 만드는 경우
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	dp[k] = (dp[k] == MAX) ? -1 : dp[k];
	cout << dp[k];

	return 0;
}
