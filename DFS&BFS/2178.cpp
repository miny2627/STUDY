#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[101][101] = { 0 };
int dist[101][101] = { 0 };
bool check[101][101];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs() {
	check[0][0] = true;
	dist[0][0]++;

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (arr[nx][ny] == 0 || check[nx][ny]) continue;
			
			check[nx][ny] = true;
 			dist[nx][ny] = dist[curX][curY] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	cout << dist[n - 1][m - 1];
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	bfs();

	return 0;
}
