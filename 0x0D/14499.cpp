#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

int N, M, x, y, K;
int board[20][20];
int num[7];
int d_top = 1, d_bottom = 6, d_front = 5, d_rear = 2, d_left = 4, d_right = 3;

void east() {
	int tmp = d_top;
	d_top = d_left;
	d_left = d_bottom;
	d_bottom = d_right;
	d_right = tmp;
}

void west() {
	int tmp = d_top;
	d_top = d_right;
	d_right = d_bottom;
	d_bottom = d_left;
	d_left = tmp;
}

void north() {
	int tmp = d_top;
	d_top = d_front;
	d_front = d_bottom;
	d_bottom = d_rear;
	d_rear = tmp;
}

void south() {
	int tmp = d_top;
	d_top = d_rear;
	d_rear = d_bottom;
	d_bottom = d_front;
	d_front = tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> x >> y >> K;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> board[x][y];
		}
	}

	int mv;
	for (int i = 0; i < K; i++) {
		cin >> mv;
		
		int nx = x + dx[mv];
		int ny = y + dy[mv];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		x = nx; y = ny;

		if (mv == 1) {
			east();
		}
		else if (mv == 2) {
			west();
		}
		else if (mv == 3) {
			north();
		}
		else { // mv == 4
			south();
		}

		if (board[x][y] == 0) board[x][y] = num[d_bottom];
		else {
			num[d_bottom] = board[x][y];
			board[x][y] = 0;
		}

		cout << num[d_top] << '\n';
	}
}