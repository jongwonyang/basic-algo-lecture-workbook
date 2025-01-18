#include <bits/stdc++.h>
using namespace std;

int N, M, H;
int board[31][11]; // -1: ¿Þ, 0: ¾Æ·¡, 1: ¿À

bool game() {
	for (int i = 1; i <= N; i++) {
		int t = i;
		for (int j = 1; j <= H; j++) {
			t += board[j][t];
		}
		//cout << i << " -> " << t << '\n';
		if (i != t) return false;
	}
	return true;
}

int ans = -1;
void func(int idx, int cnt, int sa, int sb) {
	if (idx == cnt) {
		if (game()) ans = cnt;
		return;
	}

	for (int a = sa; a <= H; a++) {
		if (a != sa) sb = 1;
		for (int b = sb; b <= N - 1; b++) {
			if (board[a][b] != 0 || board[a][b + 1] != 0) continue;
			board[a][b] = 1;
			board[a][b + 1] = -1;
			func(idx + 1, cnt, a, b);
			board[a][b] = 0;
			board[a][b + 1] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
		board[a][b + 1] = -1;
	}

	func(0, 0, 1, 1);
	if (ans != -1) {
		cout << ans;
		return 0;
	}

	func(0, 1, 1, 1);
	if (ans != -1) {
		cout << ans;
		return 0;
	}

	func(0, 2, 1, 1);
	if (ans != -1) {
		cout << ans;
		return 0;
	}

	func(0, 3, 1, 1);
	if (ans != -1) {
		cout << ans;
		return 0;
	}

	cout << -1;
}