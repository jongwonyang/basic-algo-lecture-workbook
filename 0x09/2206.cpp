#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char board[1000][1000];
int dist[1000][1000][2]; // x, y, broken

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int x = 0; x < N; x++) {
		string line;
		cin >> line;
		for (int y = 0; y < M; y++) {
			board[x][y] = line[y];
			dist[x][y][0] = -1;
			dist[x][y][1] = -1;
		}
	}

	queue<tuple<int, int, int>> q; // x, y, broken
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 1;
	
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int cx, cy, broken;
		tie(cx, cy, broken) = cur;

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
				q.push({ nx, ny, broken });
				dist[nx][ny][broken] = dist[cx][cy][broken] + 1;
			}
			
			if (broken == 0 && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
				q.push({ nx, ny, 1 });
				dist[nx][ny][1] = dist[cx][cy][broken] + 1;
			}
		}
	}

	int min_dist = INT_MAX;
	for (int b = 0; b <= 1; b++) {
		int d = dist[N - 1][M - 1][b];
		if (d != -1) min_dist = min(min_dist, d);
	}

	if (min_dist == INT_MAX) cout << -1;
	else cout << min_dist;
}