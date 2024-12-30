#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int hx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int hy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int K, W, H;
int board[200][200];
int dist[200][200][31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> W >> H;
	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			cin >> board[x][y];
		}
	}

	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			for (int z = 0; z <= K; z++) {
				dist[x][y][z] = -1;
			}
		}
	}

	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int cx, cy, cz;
		tie(cx, cy, cz) = cur;
		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (board[nx][ny] == 1 || dist[nx][ny][cz] != -1) continue;
			q.push({ nx, ny, cz });
			dist[nx][ny][cz] = dist[cx][cy][cz] + 1;
		}
		if (cz == K) continue;
		for (int d = 0; d < 8; d++) {
			int nx = cx + hx[d];
			int ny = cy + hy[d];
			int nz = cz + 1;
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (board[nx][ny] == 1 || dist[nx][ny][nz] != -1) continue;
			q.push({ nx, ny, nz });
			dist[nx][ny][nz] = dist[cx][cy][cz] + 1;
		}
	}

	int ans = INT_MAX;
	for (int z = 0; z <= K; z++) {
		if (dist[H - 1][W - 1][z] != -1) ans = min(ans, dist[H - 1][W - 1][z]);
	}
	if (ans == INT_MAX) cout << -1;
	else cout << ans;
}