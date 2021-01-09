#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, dp[50] = { 0,1 };
	cin >> n;

	for (int i = 2; i <= 45; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << endl;

	return 0;
}
