#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int N = 12;
const int M = 6;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char board[N][M];
bool vis[N][M];

bool bfs(int x, int y) {
	char c = board[x][y];

	queue<pair<int, int>> q;
	q.push({ x, y });
	vis[x][y] = true;

	vector<pair<int, int>> hist;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		hist.push_back(cur);
		for (int d = 0; d < 4; d++) {
			int nx = cur.X + dx[d];
			int ny = cur.Y + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (vis[nx][ny] || board[nx][ny] != c) continue;
			q.push({ nx, ny });
			vis[nx][ny] = true;
		}
	}

	if (hist.size() >= 4) {
		for (auto h : hist) {
			board[h.X][h.Y] = '.';
		}
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string line;
	for (int x = 0; x < N; x++) {
		cin >> line;
		for (int y = 0; y < M; y++) {
			board[x][y] = line[y];
		}
	}

	int ans = 0;
	while (true) {
		for (int x = 0; x < N; x++) fill(vis[x], vis[x] + M, false);
		
		bool pop = false;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (vis[x][y]) continue;
				if (board[x][y] == '.') vis[x][y] = true;
				else {
					if (bfs(x, y)) pop = true;
				}
			}
		}

		for (int y = 0; y < M; y++) {
			int idx = N - 1;
			for (int x = N - 1; x >= 0; x--) {
				if (board[x][y] != '.') board[idx--][y] = board[x][y];
			}
			for (int x = idx; x >= 0; x--) {
				board[x][y] = '.';
			}
		}

		if (!pop) break;
		ans++;
	}

	cout << ans;
}