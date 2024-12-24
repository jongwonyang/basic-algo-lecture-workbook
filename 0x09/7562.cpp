#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int L;
		cin >> L;

		int x, y, tx, ty;
		cin >> x >> y >> tx >> ty;

		queue<pair<int, int>> q;
		int dist[300][300] = {};
		
		q.push({ x, y });
		dist[x][y] = 1;

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int d = 0; d < 8; d++) {
				int nx = cur.X + dx[d];
				int ny = cur.Y + dy[d];

				if (nx < 0 || nx >= L || ny < 0 || ny >= L) continue;
				if (dist[nx][ny] != 0) continue;

				q.push({ nx, ny });
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			}
		}

		cout << dist[tx][ty] - 1 << '\n';
	}
}