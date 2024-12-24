#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	
	while (T--) {
		int N, M, K;
		cin >> N >> M >> K;

		int board[50][50] = {};

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}

		int count = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (board[x][y] == 1) {
					queue<pair<int, int>> q;
					q.push({ x, y });
					board[x][y] = 0;
					while (!q.empty()) {
						pair<int, int> cur = q.front(); q.pop();
						for (int d = 0; d < 4; d++) {
							int nx = cur.X + dx[d];
							int ny = cur.Y + dy[d];

							if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
							if (board[nx][ny] == 0) continue;

							q.push({ nx, ny });
							board[nx][ny] = 0;
						}
					}
					count++;
				}
			}
		}

		cout << count << '\n';
	}
}