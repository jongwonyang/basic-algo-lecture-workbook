#include <bits/stdc++.h>
using namespace std;

int dz[] = { 0, 0, 0, 0, 1, -1 };
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };

int M, N, H;
int board[100][100][100]; // z x y
int dist[100][100][100]; // z x y
queue<tuple<int, int, int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;
	
	for (int z = 0; z < H; z++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				cin >> board[z][x][y];
				if (board[z][x][y] == 1) {
					q.push({ z, x, y });
					dist[z][x][y] = 1;
				}
				if (board[z][x][y] == -1) dist[z][x][y] = -1;
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int cz, cx, cy;
		tie(cz, cx, cy) = cur;
		for (int d = 0; d < 6; d++) {
			int nz = cz + dz[d];
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if (nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nz][nx][ny] == -1 || dist[nz][nx][ny] != 0) continue;

			q.push({ nz, nx, ny });
			dist[nz][nx][ny] = dist[cz][cx][cy] + 1;
		}
	}

	int ans = 1;
	for (int z = 0; z < H; z++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (dist[z][x][y] == 0) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[z][x][y]);
			}
		}
	}

	cout << ans - 1;
}