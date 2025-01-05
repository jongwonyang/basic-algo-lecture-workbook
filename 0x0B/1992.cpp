#include <bits/stdc++.h>
using namespace std;

int N;
char board[64][64];
string ans;

void func(int x, int y, int n) {
	if (n == 1) {
		ans += board[x][y];
		return;
	}

	char c = board[x][y];
	bool identical = true;
	for (int nx = x; nx < x + n; nx++) {
		for (int ny = y; ny < y + n; ny++) {
			if (board[nx][ny] != c) {
				identical = false;
				goto out;
			}
		}
	}
out:
	if (identical) ans += c;
	else {
		ans += '(';
		func(x, y, n / 2);
		func(x, y + n / 2, n / 2);
		func(x + n / 2, y, n / 2);
		func(x + n / 2, y + n / 2, n / 2);
		ans += ')';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int x = 0; x < N; x++) {
		string line;
		cin >> line;
		for (int y = 0; y < N; y++) {
			board[x][y] = line[y];
		}
	}

	func(0, 0, N);
	cout << ans;
}