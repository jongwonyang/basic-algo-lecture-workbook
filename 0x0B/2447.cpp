#include <bits/stdc++.h>
using namespace std;

int N;
char ans[7000][7000];

void func(int x, int y, int n) {
	if (n == 1) {
		ans[x][y] = '*';
		return;
	}

	int d = n / 3;
	func(x, y, d);
	func(x, y + d, d);
	func(x, y + d + d, d);
	func(x + d, y, d);
	for (int nx = x + d; nx < x + d + d; nx++) {
		for (int ny = y + d; ny < y + d + d; ny++) {
			ans[nx][ny] = ' ';
		}
	}
	func(x + d, y + d + d, d);
	func(x + d + d, y, d);
	func(x + d + d, y + d, d);
	func(x + d + d, y + d + d, d);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	func(0, 0, N);

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cout << ans[x][y];
		}
		cout << '\n';
	}
}