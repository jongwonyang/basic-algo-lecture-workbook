#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 0, 0, 1, -1 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { -1, 1, 0, 0, 0, 0 };

int board[5][5][5];
bool select[5];
int cube[5][5][5];

int bfs() {
	queue<tuple<int, int, int>> q;
	int dist[5][5][5];

	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			for (int z = 0; z < 5; z++) {
				dist[x][y][z] = -1;
			}
		}
	}

	q.push({ 0, 0, 0 });
	dist[0][0][0] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int x, y, z;
		tie(x, y, z) = cur;
		for (int d = 0; d < 6; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			int nz = z + dz[d];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
			if (cube[nx][ny][nz] == 0 || dist[nx][ny][nz] != -1) continue;
			q.push({ nx, ny, nz });
			dist[nx][ny][nz] = dist[x][y][z] + 1;
		}
	}

	return dist[4][4][4];
}

void rot(int i) {
	int tmp[5][5];
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			tmp[x][y] = board[i][x][y];
		}
	}
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			board[i][y][4 - x] = tmp[x][y];
		}
	}
}

int ans = INT_MAX;
void func(int idx) {
	if (idx == 5) {
		int d = bfs();
		if (d != -1) ans = min(ans, d);
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (select[i]) continue;
		select[i] = true;
		for (int d = 0; d < 4; d++) {
			for (int x = 0; x < 5; x++) {
				for (int y = 0; y < 5; y++) {
					cube[idx][x][y] = board[i][x][y];
				}
			}
			rot(i);
		}
		func(idx + 1);
		select[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				cin >> board[i][x][y];
			}
		}
	}

	func(0);

	if (ans == INT_MAX) cout << -1;
	else cout << ans;
}