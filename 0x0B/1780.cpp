#include <bits/stdc++.h>
using namespace std;

int N;
int board[2200][2200];
int cnt[3];

void func(int x, int y, int n) {
	if (n == 1) {
		cnt[board[x][y] + 1]++;
		return;
	}

	int num = board[x][y];
	bool identical = true;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[i][j] != num) {
				identical = false;
				goto out;
			}
		}
	}
out:
	if (identical) {
		cnt[num + 1]++;
	}
	else {
		for (int nx = x; nx < x + n; nx += n / 3) {
			for (int ny = y; ny < y + n; ny += n / 3) {
				func(nx, ny, n / 3);
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

	func(0, 0, N);

	for (int c : cnt) cout << c << '\n';
}