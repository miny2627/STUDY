#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1000001

using namespace std;

bool check[MAX];

int bfs(int f, int s, int g, int u, int d) {
	queue<pair<int, int>> q;
	q.push(make_pair(s, 0));
	check[s] = true;

	while (!q.empty()) {
		int loc = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (loc == g) return cost;

		if (loc + u <= f && !check[loc + u]) {
			q.push(make_pair(loc + u, cost + 1));
			check[loc + u] = true;
		}
		if (loc - d > 0 && !check[loc - d]) {
			q.push(make_pair(loc - d, cost + 1));
			check[loc - d] = true;
		}
	}

	return -1;
}

int main() {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	int ans = bfs(f, s, g, u, d);
	if (ans == -1) cout << "use the stairs";
	else cout << ans;

	return 0;
}
