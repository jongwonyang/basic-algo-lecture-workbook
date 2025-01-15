#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 0, 0, -1, 1 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { -1, 1, 0, 0, 0, 0 };

int board[4][5][5][5]; // [d][z][x][y]
int cube[5][5][5]; // [z][x][y]
bool sel[5];

int bfs() {
	if (cube[0][0][0] == 0 || cube[4][4][4] == 0) return -1;

	queue<tuple<int, int, int>> q;
	int dist[5][5][5]; // [z][x][y]

	for (int z = 0; z < 5; z++) {
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				dist[z][x][y] = -1;
			}
		}
	}

	q.push({ 0, 0, 0 });
	dist[0][0][0] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int z, x, y;
		tie(z, x, y) = cur;
		for (int d = 0; d < 6; d++) {
			int nz = z + dz[d];
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nz < 0 || nz >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (cube[nz][nx][ny] == 0 || dist[nz][nx][ny] != -1) continue;
			q.push({ nz, nx, ny });
			dist[nz][nx][ny] = dist[z][x][y] + 1;
		}
	}

	return dist[4][4][4];
}

int ans = INT_MAX;
void func(int z) {
	if (z == 5) {
		int d = bfs();
		if (d == -1) return;
		ans = min(ans, d);
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (sel[i]) continue;
		sel[i] = true;
		for (int d = 0; d < 4; d++) {
			for (int x = 0; x < 5; x++) {
				for (int y = 0; y < 5; y++) {
					cube[z][x][y] = board[d][i][x][y];
				}
			}
			func(z + 1);
		}
		sel[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int z = 0; z < 5; z++) {
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				cin >> board[0][z][x][y];
			}
		}
		for (int d = 1; d <= 3; d++) {
			for (int x = 0; x < 5; x++) {
				for (int y = 0; y < 5; y++) {
					board[d][z][x][y] = board[d - 1][z][4 - y][x];
				}
			}
		}
	}

	func(0);

	if (ans == INT_MAX) cout << -1;
	else cout << ans;
}