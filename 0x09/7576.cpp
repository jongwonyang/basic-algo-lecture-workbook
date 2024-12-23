#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int board[1000][1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> M >> N;

	queue<pair<int, int>> q;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> board[x][y];
			if (board[x][y] == 1) {
				q.push({ x, y });
			}
		}
	}

	int day = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			pair<int, int> cur = q.front(); q.pop();
			for (int d = 0; d < 4; d++) {
				int nx = cur.X + dx[d];
				int ny = cur.Y + dy[d];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (board[nx][ny] != 0) continue;

				q.push({ nx, ny });
				board[nx][ny] = 1;
			}
		}
		day++;
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (board[x][y] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << day - 1;
}