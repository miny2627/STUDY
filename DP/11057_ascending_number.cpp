#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 1001
using namespace std;

int main() {
	int n, sum = 0;
	int dp[MAX][10] = {};
	cin >> n;
	
	for (int i = 0; i < 10; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][k] += dp[i - 1][j];
				dp[i][k] %= 10007;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		sum += dp[n - 1][i];
	}
	cout << sum % 10007 << endl;

	return 0;
}
