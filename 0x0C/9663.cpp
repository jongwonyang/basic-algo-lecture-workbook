#include <bits/stdc++.h>
using namespace std;

const int MX = 15;

int N;
bool used_y[MX];
bool used_diag1[MX * 2];
bool used_diag2[MX * 2];

int cnt = 0;
void func(int x) {
	if (x == N) {
		cnt++;
		return;
	}

	for (int y = 0; y < N; y++) {
		if (used_y[y] || used_diag1[x - y + N - 1] || used_diag2[x + y]) continue;
		used_y[y] = true;
		used_diag1[x - y + N - 1] = true;
		used_diag2[x + y] = true;
		func(x + 1);
		used_y[y] = false;
		used_diag1[x - y + N - 1] = false;
		used_diag2[x + y] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	func(0);
	cout << cnt;
}