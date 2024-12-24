#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char board[1000][1000];
int dist_f[1000][1000];
int dist_s[1000][1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int W, H;
		cin >> W >> H;

		queue<pair<int, int>> qf;
		queue<pair<int, int>> qs;
		for (int x = 0; x < H; x++) {
			for (int y = 0; y < W; y++) {
				dist_f[x][y] = dist_s[x][y] = 0;
			}
		}

		for (int x = 0; x < H; x++) {
			string line;
			cin >> line;
			for (int y = 0; y < W; y++) {
				board[x][y] = line[y];
				if (board[x][y] == '*') {
					qf.push({ x, y });
					dist_f[x][y] = 1;
				}
				else if (board[x][y] == '@') {
					qs.push({ x, y });
					dist_s[x][y] = 1;
				}
			}
		}

		while (!qf.empty()) {
			auto cur = qf.front(); qf.pop();
			for (int d = 0; d < 4; d++) {
				int nx = cur.X + dx[d];
				int ny = cur.Y + dy[d];

				if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
				if (board[nx][ny] == '#' || dist_f[nx][ny] > 0) continue;

				qf.push({ nx, ny });
				dist_f[nx][ny] = dist_f[cur.X][cur.Y] + 1;
			}
		}

		bool found = false;
		while (!qs.empty()) {
			auto cur = qs.front(); qs.pop();
			for (int d = 0; d < 4; d++) {
				int nx = cur.X + dx[d];
				int ny = cur.Y + dy[d];

				if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
					cout << dist_s[cur.X][cur.Y] << '\n';
					found = true;
					break;
				}
				if (board[nx][ny] == '#' || dist_s[nx][ny] > 0) continue;
				if (dist_f[nx][ny] > 0 && dist_s[cur.X][cur.Y] + 1 >= dist_f[nx][ny]) continue;

				qs.push({ nx, ny });
				dist_s[nx][ny] = dist_s[cur.X][cur.Y] + 1;
			}
			if (found) break;
		}

		if (!found) cout << "IMPOSSIBLE" << '\n';
	}
}