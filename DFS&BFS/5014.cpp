#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1000001

using namespace std;

int dist[MAX] = { 0 };

int bfs(int f, int s, int g, int u, int d) {
	queue<int> q;
	q.push(s);
	dist[s] = 1;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == g) return dist[g] - 1;

		int next[2] = { curr + u, curr - d };
		for (int i = 0; i < 2; i++) {
			if (1 <= next[i] && next[i] <= f && !dist[next[i]]) {
				dist[next[i]] = dist[curr] + 1;
				q.push(next[i]);
			}
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
