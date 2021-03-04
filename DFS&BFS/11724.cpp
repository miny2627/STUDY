#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1001

using namespace std;

vector<int> graph[MAX];
bool check[MAX];

void dfs(int start) {
	check[start] = true;

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];

		if (!check[next]) dfs(next);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = true;
	
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];

			if (!check[next]) {
				q.push(next);
				check[next] = true;
			}
		}
	}
}

int main() {
	int n, m, cnt = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			cnt++;
			bfs(i);
			// dfs(i);
		}
	}

	cout << cnt;

	return 0;
}
