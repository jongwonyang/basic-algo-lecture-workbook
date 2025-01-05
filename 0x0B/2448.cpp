#include <bits/stdc++.h>
using namespace std;

int N;
char ans[3100][6200];

void func(int n, int x, int y) {
	if (n == 3) {
		ans[x][y] = '*';
		ans[x + 1][y - 1] = '*';
		ans[x + 1][y + 1] = '*';
		ans[x + 2][y - 2] = '*';
		ans[x + 2][y - 1] = '*';
		ans[x + 2][y] = '*';
		ans[x + 2][y + 1] = '*';
		ans[x + 2][y + 2] = '*';
		return;
	}

	func(n / 2, x, y);
	func(n / 2, x + n / 2, y - n / 2);
	func(n / 2, x + n / 2, y + n / 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) fill(ans[i], ans[i] + N * 2, ' ');

	func(N, 0, N - 1);

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N * 2; y++) {
			cout << ans[x][y];
		}
		cout << '\n';
	}
}