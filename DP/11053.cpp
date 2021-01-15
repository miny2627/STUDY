#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, sum = 0;
	int * arr, * dp;
	cin >> n;

	arr = new int[n];
	dp = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		sum = max(sum, dp[i]);
	}

	cout << sum;

	return 0;
}
