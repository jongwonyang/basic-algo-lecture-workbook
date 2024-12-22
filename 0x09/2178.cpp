#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
int board[100][100];
int dist[100][100];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	string line;
	for (int x = 0; x < N; x++) {
		cin >> line;
		for (int y = 0; y < M; y++) {
			board[x][y] = line[y] - '0';
		}
		fill(dist[x], dist[x] + M, -1);
	}

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	dist[0][0] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = cur.X + dx[d];
			int ny = cur.Y + dy[d];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == 0 || dist[nx][ny] != -1) continue;	

			q.push({ nx, ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
		}
	}

	cout << dist[N - 1][M - 1];
}