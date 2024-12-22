#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[500][500];
bool visited[500][500];

int dx[] = { -1, 1, 0, 0 }; // ╩С, го, аб, ©Л
int dy[] = { 0, 0, -1, 1 }; // ╩С, го, аб, ©Л

int bfs(int x, int y, int n, int m) {
	queue<pair<int, int>> q;

	q.push({ x, y });
	visited[x][y] = true;

	int area = 1;
	while (!q.empty()) {
		int cx = q.front().X;
		int cy = q.front().Y;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
				board[nx][ny] == 1 && !visited[nx][ny]) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
				area++;
			}
		}
	}

	return area;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> board[x][y];
		}
	}

	int count = 0, max_area = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (board[x][y] == 1 && !visited[x][y]) {
				count++;
				max_area = max(max_area, bfs(x, y, n, m));
			}
		}
	}

	cout << count << '\n';
	cout << max_area << '\n';
}