#include <bits/stdc++.h>
using namespace std;

int N, M, K, R, C;
int board[40][40];
int sticker[10][10];

void print_board() {
	cout << '\n';
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cout << board[x][y] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void rot() {
	int ns[10][10];
	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			ns[y][R - 1 - x] = sticker[x][y];
		}	
	}
	swap(R, C);
	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			sticker[x][y] = ns[x][y];
		}
	}
}

bool chk(int x, int y) {
	for (int sx = 0; sx < R; sx++) {
		for (int sy = 0; sy < C; sy++) {
			int bx = x + sx;
			int by = y + sy;
			if (bx < 0 || bx >= N || by < 0 || by >= M) return false;
			if (sx < 0 || sx >= R || sy < 0 || sy >= C) return false;
			if (sticker[sx][sy] == 1 && board[bx][by] == 1) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> R >> C;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				cin >> sticker[r][c];
			}
		}
		for (int d = 0; d < 4; d++) {
			for (int x = 0; x < N; x++) {
				for (int y = 0; y < M; y++) {
					if (chk(x, y)) {
						for (int sx = 0; sx < R; sx++) {
							for (int sy = 0; sy < C; sy++) {
								if (sticker[sx][sy] == 1) board[x + sx][y + sy] = 1;
							}
						}
						goto out;
					}
				}
			}
			rot();
		}
	out:;
	}

	int ans = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (board[x][y] == 1) ans++;
		}
	}
	cout << ans;
}