#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100001

using namespace std;

bool check[MAX];

int bfs(int n, int k) {
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	check[n] = true;

	while (!q.empty()) {
		int loc = q.front().first;
		int time = q.front().second;
		q.pop();

		if (loc == k) return time;

		if (loc + 1 < MAX && !check[loc + 1]) {
			q.push(make_pair(loc + 1, time + 1));
			check[loc + 1] = true;
		}
		if (loc - 1 >= 0 && !check[loc - 1]) {
			q.push(make_pair(loc - 1, time + 1));
			check[loc - 1] = true;
		}
		if (loc * 2 < MAX && !check[loc * 2]) {
			q.push(make_pair(loc * 2, time + 1));
			check[loc * 2] = true;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << bfs(n, k);

	return 0;
}
