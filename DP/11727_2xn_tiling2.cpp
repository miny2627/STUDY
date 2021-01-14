#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n, dp[1001];
	cin >> n;
	
	dp[0] = 1;
	dp[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
		// n-1의 경우 1x2, n-2의 경우 2x1 & 2x2
	}
	
	cout << dp[n];

	return 0;
}
