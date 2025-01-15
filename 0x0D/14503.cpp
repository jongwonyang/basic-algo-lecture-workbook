#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, 0, 1, 0 }; // ºÏ µ¿ ³² ¼­
int dy[] = { 0, 1, 0, -1 }; // ºÏ µ¿ ³² ¼­

int N, M;
int board[50][50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, d;
	cin >> N >> M >> x >> y >> d;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> board[x][y];
		}
	}
	
	int ans = 0;
	while (true) {
		loop:
		if (board[x][y] == 0) {
			board[x][y] = 2;
			ans++;
		}
		for (int i = 0; i < 4; i++) {
			d--; if (d < 0) d = 3;
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == 0) {
				x = nx;
				y = ny;
				goto loop;
			}
		}
		int b = (d + 2) % 4;
		int bx = x + dx[b];
		int by = y + dy[b];
		if (bx < 0 || bx >= N || by < 0 || by >= M || board[bx][by] == 1) break;
		x = bx;
		y = by;
	}
	cout << ans;
}