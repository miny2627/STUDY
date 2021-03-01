#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(vector<int>* graph, bool* check) {
	queue<int> q;
	q.push(1);

	check[1] = true;
	int cnt = 0;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < graph[curr].size(); i++) {
			if (!check[graph[curr][i]]) {
				q.push(graph[curr][i]);
				check[graph[curr][i]] = true;
			}
		}
	}
	cout << cnt - 1;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int>* graph = new vector<int>[n + 1];
	bool* check = new bool[n + 1];
	fill(check, check + n + 1, false);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bfs(graph, check);

	return 0;
}
