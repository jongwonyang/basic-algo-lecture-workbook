#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N;
int board[300][300];
int dist[300][300];

void init_dist() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			dist[x][y] = -1;
		}
	}
}

void island() {
	init_dist();

	int island_number = 1;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (board[x][y] == 1 && dist[x][y] == -1) {
				queue<pair<int, int>> q;
				q.push({ x, y });
				dist[x][y] = 0;
				board[x][y] = island_number;
				while (!q.empty()) {
					auto cur = q.front(); q.pop();
					for (int d = 0; d < 4; d++) {
						int nx = cur.X + dx[d];
						int ny = cur.Y + dy[d];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (board[nx][ny] == 0 || dist[nx][ny] != -1) continue;
						q.push({ nx, ny });
						dist[nx][ny] = dist[cur.X][cur.Y] + 1;
						board[nx][ny] = island_number;
					}
				}
				island_number++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> board[x][y];
		}
	}

	island();

	init_dist();
	queue<pair<int, int>> q;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (board[x][y] != 0) {
				q.push({ x, y });
				dist[x][y] = 0;
			}
		}
	}

	int ans = INT_MAX;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.X + dx[d];
			int ny = cur.Y + dy[d];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (board[nx][ny] == board[cur.X][cur.Y]) continue;
			if (board[nx][ny] != 0) {
				ans = min(ans, dist[nx][ny] + dist[cur.X][cur.Y]);
				continue;
			}
			if (dist[nx][ny] != -1) continue;
			q.push({ nx, ny });
			board[nx][ny] = board[cur.X][cur.Y];
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
		}
	}

	cout << ans;
}