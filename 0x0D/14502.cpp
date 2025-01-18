#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N, M;
int board[8][8];
vector<pair<int, int>> virus;

int bfs() {
	queue<pair<int, int>> q;
	int tmp[8][8];
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			tmp[x][y] = board[x][y];
		}
	}

	for (auto v : virus) q.push({ v.X, v.Y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.X + dx[d];
			int ny = cur.Y + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (tmp[nx][ny] != 0) continue;
			q.push({ nx, ny });
			tmp[nx][ny] = 2;
		}
	}
	
	int safe = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (tmp[x][y] == 0) safe++;
		}
	}
	return safe;
}

int ans = 0;
void func(int idx, int sx, int sy) {
	if (idx == 3) {
		// 벽 설치 완료
		int safe = bfs();
		ans = max(ans, safe);
		return;
	}

	for (int x = sx; x < N; x++) {
		if (x != sx) sy = 0;
		for (int y = sy; y < M; y++) {
			if (board[x][y] == 0) {
				board[x][y] = 3;
				func(idx + 1, x, y);
				board[x][y] = 0;
			}
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
			if (board[x][y] == 2) virus.push_back({ x, y });
		}
	}

	func(0, 0, 0);

	cout << ans;
}