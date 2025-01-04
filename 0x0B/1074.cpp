#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c) {
	if (n == 0) return 0;

	int d = 1 << (n - 1);
	int s = d * d;

	if (r < d && c < d) return func(n - 1, r, c);
	if (r < d && c >= d) return s + func(n - 1, r, c - d);
	if (r >= d && c < d) return s + s + func(n - 1, r - d, c);
	return s + s + s + func(n - 1, r - d, c - d);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, R, C;
	cin >> N >> R >> C;

	cout << func(N, R, C);
}