#include <bits/stdc++.h>
using namespace std;

int board[128][128];
int cnt[2];

void func(int x, int y, int n) {
	if (n == 1) {
		cnt[board[x][y]]++;
		return;
	}

	int num = board[x][y];
	bool identical = true;
	for (int nx = x; nx < x + n; nx++) {
		for (int ny = y; ny < y + n; ny++) {
			if (board[nx][ny] != num) {
				identical = false;
				goto out;
			}
		}
	}
out:
	if (identical) cnt[num]++;
	else {
		func(x, y, n / 2);
		func(x, y + n / 2, n / 2);
		func(x + n / 2, y, n / 2);
		func(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> board[x][y];
		}
	}

	func(0, 0, N);

	for (int c : cnt) cout << c << '\n';
}