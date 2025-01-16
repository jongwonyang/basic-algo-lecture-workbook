#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[] = { -1, 0, 1, 0 }; // ºÏ µ¿ ³² ¼­
int dy[] = { 0, 1, 0, -1 }; // ºÏ µ¿ ³² ¼­

int N, K, L;
bool apple[101][101]; // 1 ~ 100
char mv[10001]; // 1 ~ 10000
bool snake[101][101]; // 1 ~ 100
deque<pair<int, int>> dq;

void print_snake() {
	cout << '\n';
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cout << snake[x][y] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int solve() {
	int d = 1;
	snake[1][1] = true;
	dq.push_back({ 1, 1 });

	int t = 1;
	while (true) {
		auto head = dq.front();
		int nx = head.X + dx[d];
		int ny = head.Y + dy[d];
		if (nx <= 0 || nx > N || ny <= 0 || ny > N || snake[nx][ny]) break;
		if (apple[nx][ny]) {
			apple[nx][ny] = false;
		}
		else {
			auto tail = dq.back(); dq.pop_back();
			snake[tail.X][tail.Y] = false;
		}
		snake[nx][ny] = true;
		dq.push_front({ nx, ny });

		if (mv[t] == 'L') d = (d + 3) % 4;
		if (mv[t] == 'D') d = (d + 1) % 4;
		t++;
	}

	return t;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	int r, c;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		apple[r][c] = true;
	}
	cin >> L;
	int x;
	char d;
	for (int i = 0; i < L; i++) {
		cin >> x >> d;
		mv[x] = d;
	}

	int ans = solve();
	cout << ans;
}