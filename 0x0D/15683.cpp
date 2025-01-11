#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
int board[8][8];
int watch[8][8];
vector<pair<int, int>> cctv;

int dx[] = { 0, 1, 0, -1 }; // >, v, <, ^
int dy[] = { 1, 0, -1, 0 }; // >, v, <, ^

void fill_line(int x, int y, int d, int k) {
	while (true) {
		if (x < 0 || x >= N || y < 0 || y >= M) break;
		if (board[x][y] == 6) break;
		watch[x][y] += k;
		x += dx[d];
		y += dy[d];
	}
}

int ans = INT_MAX;
void func(int idx) {
	if (idx == cctv.size()) {
		// 0의 개수를 센 뒤 최소값으로 갱신
		int cnt = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (board[x][y] != 6 && watch[x][y] == 0) cnt++;
			}
		}
		ans = min(ans, cnt);
		return;
	}

	int x = cctv[idx].X;
	int y = cctv[idx].Y;
	int k = board[x][y];

	if (k == 1) {
		for (int d = 0; d < 4; d++) {
			fill_line(x, y, d, 1);
			func(idx + 1);
			fill_line(x, y, d, -1);
		}
	}
	else if (k == 2) {
		fill_line(x, y, 0, 1);
		fill_line(x, y, 2, 1);
		func(idx + 1);
		fill_line(x, y, 0, -1);
		fill_line(x, y, 2, -1);

		fill_line(x, y, 1, 1);
		fill_line(x, y, 3, 1);
		func(idx + 1);
		fill_line(x, y, 1, -1);
		fill_line(x, y, 3, -1);
	}
	else if (k == 3) {
		fill_line(x, y, 0, 1);
		fill_line(x, y, 3, 1);
		func(idx + 1);
		fill_line(x, y, 0, -1);
		fill_line(x, y, 3, -1);

		fill_line(x, y, 0, 1);
		fill_line(x, y, 1, 1);
		func(idx + 1);
		fill_line(x, y, 0, -1);
		fill_line(x, y, 1, -1);

		fill_line(x, y, 1, 1);
		fill_line(x, y, 2, 1);
		func(idx + 1);
		fill_line(x, y, 1, -1);
		fill_line(x, y, 2, -1);

		fill_line(x, y, 2, 1);
		fill_line(x, y, 3, 1);
		func(idx + 1);
		fill_line(x, y, 2, -1);
		fill_line(x, y, 3, -1);
	}
	else if (k == 4) {
		fill_line(x, y, 0, 1);
		fill_line(x, y, 2, 1);
		fill_line(x, y, 3, 1);
		func(idx + 1);
		fill_line(x, y, 0, -1);
		fill_line(x, y, 2, -1);
		fill_line(x, y, 3, -1);

		fill_line(x, y, 0, 1);
		fill_line(x, y, 1, 1);
		fill_line(x, y, 3, 1);
		func(idx + 1);
		fill_line(x, y, 0, -1);
		fill_line(x, y, 1, -1);
		fill_line(x, y, 3, -1);

		fill_line(x, y, 0, 1);
		fill_line(x, y, 1, 1);
		fill_line(x, y, 2, 1);
		func(idx + 1);
		fill_line(x, y, 0, -1);
		fill_line(x, y, 1, -1);
		fill_line(x, y, 2, -1);

		fill_line(x, y, 1, 1);
		fill_line(x, y, 2, 1);
		fill_line(x, y, 3, 1);
		func(idx + 1);
		fill_line(x, y, 1, -1);
		fill_line(x, y, 2, -1);
		fill_line(x, y, 3, -1);
	}
	else { // 5
		fill_line(x, y, 0, 1);
		fill_line(x, y, 1, 1);
		fill_line(x, y, 2, 1);
		fill_line(x, y, 3, 1);
		func(idx + 1);
		fill_line(x, y, 0, -1);
		fill_line(x, y, 1, -1);
		fill_line(x, y, 2, -1);
		fill_line(x, y, 3, -1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> board[x][y];
			if (0 < board[x][y] && board[x][y] < 6)
				cctv.push_back({ x, y });
		}
	}

	func(0);

	cout << ans;
}