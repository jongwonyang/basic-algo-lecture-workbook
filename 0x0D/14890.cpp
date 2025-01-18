#include <bits/stdc++.h>
using namespace std;

int N, L;
int board[100][100];
bool ramp[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> board[x][y];
		}
	}

	int ans = 0;
	for (int x = 0; x < N; x++) {
		fill(ramp, ramp + N, false);
		bool cross = true;
		int h = board[x][0];
		for (int y = 1; y < N; y++) {
			if (board[x][y] != h) {
				if (board[x][y] - h == 1) {
					for (int d = 1; d <= L; d++) {
						int ny = y - d;
						if (ny < 0 || ramp[ny] || board[x][y] - 1 != board[x][ny]) {
							cross = false;
							break;
						}
					}
					if (cross) {
						for (int d = 1; d <= L; d++) {
							int ny = y - d;
							ramp[ny] = true;
						}
					}
				}
				else if (board[x][y] - h == -1) {
					for (int d = 0; d < L; d++) {
						int ny = y + d;
						if (ny >= N || ramp[ny] || board[x][y - 1] - 1 != board[x][ny]) {
							cross = false;
							break;
						}
					}
					if (cross) {
						for (int d = 0; d < L; d++) {
							int ny = y + d;
							ramp[ny] = true;
						}
					}
				}
				else {
					cross = false;
				}
			}
			h = board[x][y];
		}
		if (cross) ans++;
	}
	for (int y = 0; y < N; y++) {
		fill(ramp, ramp + N, false);
		bool cross = true;
		int h = board[0][y];
		for (int x = 1; x < N; x++) {
			if (board[x][y] != h) {
				if (board[x][y] - h == 1) {
					for (int d = 1; d <= L; d++) {
						int nx = x - d;
						if (nx < 0 || ramp[nx] || board[x][y] - 1 != board[nx][y]) {
							cross = false;
							break;
						}
					}
					if (cross) {
						for (int d = 1; d <= L; d++) {
							int nx = x - d;
							ramp[nx] = true;
						}
					}
				}
				else if (board[x][y] - h == -1) {
					for (int d = 0; d < L; d++) {
						int nx = x + d;
						if (nx >= N || ramp[nx] || board[x - 1][y] - 1 != board[nx][y]) {
							cross = false;
							break;
						}
					}
					if (cross) {
						for (int d = 0; d < L; d++) {
							int nx = x + d;
							ramp[nx] = true;
						}
					}
				}
				else {
					cross = false;
				}
			}
			h = board[x][y];
		}
		if (cross) ans++;
	}

	cout << ans;
}