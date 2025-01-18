#include <bits/stdc++.h>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int N;
bool board[101][101]; // [y][x];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int x, y, d, g;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		vector<int> dir;
		dir.push_back(d);
		for (int j = 0; j < g; j++) {
			int s = dir.size();
			for (int k = s - 1; k >= 0; k--) {
				dir.push_back((dir[k] + 1) % 4);
			}
		}
		
		for (int j : dir) {
			board[y][x] = true;
			x = x + dx[j];
			y = y + dy[j];
		}
		board[y][x] = true;
	}

	int ans = 0;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (board[y][x] && board[y + 1][x] && board[y][x + 1] && board[y + 1][x + 1])
				ans++;
		}
	}
	cout << ans;
}