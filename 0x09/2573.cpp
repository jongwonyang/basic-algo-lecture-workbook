#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N, M;
int board[300][300];
bool vis[300][300];
int board_next[300][300];

int bfs() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			vis[x][y] = false;
		}
	}

	int count = 0;
	for (int x = 1; x < N - 1; x++) {
		for (int y = 1; y < M - 1; y++) {
			if (board[x][y] != 0 && !vis[x][y]) {
				count++;
				queue<pair<int, int>> q;
				q.push({ x, y });
				vis[x][y] = true;
				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int d = 0; d < 4; d++) {
						int nx = cur.X + dx[d];
						int ny = cur.Y + dy[d];

						if (board[nx][ny] == 0 || vis[nx][ny]) continue;

						q.push({ nx, ny });
						vis[nx][ny] = true;
					}
				}
			}
		}
	}
	return count;
}

void process() {
	for (int x = 1; x < N - 1; x++) {
		for (int y = 1; y < M - 1; y++) {
			board_next[x][y] = 0;
		}
	}

	for (int x = 1; x < N - 1; x++) {
		for (int y = 1; y < M - 1; y++) {
			if (board[x][y] > 0) {
				int count = 0;
				for (int d = 0; d < 4; d++) {
					int nx = x + dx[d];
					int ny = y + dy[d];
					if (board[nx][ny] == 0) count++;
				}
				board_next[x][y] = board[x][y] - count;
				if (board_next[x][y] < 0) board_next[x][y] = 0;
			}
		}
	}

	for (int x = 1; x < N - 1; x++) {
		for (int y = 1; y < M - 1; y++) {
			board[x][y] = board_next[x][y];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> board[x][y];
		}
	}

	int year = 0;
	while (true) {
		int num_island = bfs();

		if (num_island >= 2) {
			cout << year;
			break;
		}

		if (num_island == 0) {
			cout << 0;
			break;
		}

		process();

		year++;
	}
}