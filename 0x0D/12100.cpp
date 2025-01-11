#include <bits/stdc++.h>
using namespace std;

int N;
int board[20][20];
int dir[5];

int game() {
	int tmp[20][20];
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			tmp[x][y] = board[x][y];
		}
	}

	for (int d : dir) {
		if (d == 0) {
			for (int y = 0; y < N; y++) {
				int prev = -1, idx = 0;
				for (int x = 0; x < N; x++) {
					if (tmp[x][y] == 0) continue;
					if (prev == -1) prev = tmp[x][y];
					else {
						if (prev == tmp[x][y]) {
							tmp[idx++][y] = prev + tmp[x][y];
							prev = -1;
						}
						else {
							tmp[idx++][y] = prev;
							prev = tmp[x][y];
						}
					}
				}
				if (prev != -1) tmp[idx++][y] = prev;
				while (idx < N) tmp[idx++][y] = 0;
			}
		}
		else if (d == 1) {
			for (int x = 0; x < N; x++) {
				int prev = -1, idx = N - 1;
				for (int y = N - 1; y >= 0; y--) {
					if (tmp[x][y] == 0) continue;
					if (prev == -1) prev = tmp[x][y];
					else {
						if (prev == tmp[x][y]) {
							tmp[x][idx--] = prev + tmp[x][y];
							prev = -1;
						}
						else {
							tmp[x][idx--] = prev;
							prev = tmp[x][y];
						}
					}
				}
				if (prev != -1) tmp[x][idx--] = prev;
				while (idx >= 0) tmp[x][idx--] = 0;
			}
		}
		else if (d == 2) {
			for (int y = 0; y < N; y++) {
				int prev = -1, idx = N - 1;
				for (int x = N - 1; x >= 0; x--) {
					if (tmp[x][y] == 0) continue;
					if (prev == -1) prev = tmp[x][y];
					else {
						if (prev == tmp[x][y]) {
							tmp[idx--][y] = prev + tmp[x][y];
							prev = -1;
						}
						else {
							tmp[idx--][y] = prev;
							prev = tmp[x][y];
						}
					}
				}
				if (prev != -1) tmp[idx--][y] = prev;
				while (idx >= 0) tmp[idx--][y] = 0;
			}
		}
		else { // 3
			for (int x = 0; x < N; x++) {
				int prev = -1, idx = 0;
				for (int y = 0; y < N ; y++) {
					if (tmp[x][y] == 0) continue;
					if (prev == -1) prev = tmp[x][y];
					else {
						if (prev == tmp[x][y]) {
							tmp[x][idx++] = prev + tmp[x][y];
							prev = -1;
						}
						else {
							tmp[x][idx++] = prev;
							prev = tmp[x][y];
						}
					}
				}
				if (prev != -1) tmp[x][idx++] = prev;
				while (idx < N) tmp[x][idx++] = 0;
			}
		}
	}

	int mx = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			mx = max(mx, tmp[x][y]);
		}
	}
	return mx;
}

int ans = 0;
void func(int idx) {
	if (idx == 5) {
		ans = max(ans, game());
		return;
	}

	for (int d = 0; d < 4; d++) {
		dir[idx] = d;
		func(idx + 1);
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

	func(0);
	cout << ans;
}