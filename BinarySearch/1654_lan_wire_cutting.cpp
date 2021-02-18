#include <iostream>
#include <algorithm>

using namespace std;
int arr[10001];
int k, n;

int binarySearch() {
	long long low = 1, high = arr[k - 1];
	while (low <= high) {
		long long mid = (high + low) / 2;
		int tmp = 0;
		
		for (int i = 0; i < k; i++) {
			tmp += (arr[i] / mid);
		}

		if (tmp < n) high = mid - 1;
		else low = mid + 1;
	}

	return high;
}

int main() {
	int input;

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + k);
	cout << binarySearch();

	return 0;
}
