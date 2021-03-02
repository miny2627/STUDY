#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[101];
int dist[101] = { 0 };

int bfs(int x, int y) {
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == y) return dist[y];

		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];

			if (!dist[next]) {
				q.push(next);
				dist[next] = dist[curr] + 1;
			}
		}
	}
	return -1;
}

int main() {
	int n, m, x, y;
	cin >> n >> x >> y >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	cout<< bfs(x, y);

	return 0;
}
