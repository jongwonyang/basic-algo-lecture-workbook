#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char board[5][5];
bool vis[5][5];

int coord_to_idx(int x, int y) {
	return 5 * x + y;
}

void idx_to_coord(int idx, int& x, int& y) {
	x = idx / 5;
	y = idx % 5;
}

bool bfs(int x, int y, const vector<int>& sel) {
	queue<pair<int, int>> q;
	bool vis[5][5];
	for (int i = 0; i < 5; i++) fill(vis[i], vis[i] + 5, false);

	q.push({ x, y });
	vis[x][y] = true;

	int cnt = 0, nr_y = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (board[cur.X][cur.Y] == 'Y') nr_y++;
		cnt++;

		for (int d = 0; d < 4; d++) {
			int nx = cur.X + dx[d];
			int ny = cur.Y + dy[d];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (vis[nx][ny] || sel[coord_to_idx(nx, ny)] == 1) continue;
			q.push({ nx, ny });
			vis[nx][ny] = true;
		}
	}

	return cnt == 7 && nr_y <= 3;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string line;
	for (int x = 0; x < 5; x++) {
		cin >> line;
		for (int y = 0; y < 5; y++) {
			board[x][y] = line[y];
		}
	}

	vector<int> sel;
	for (int i = 0; i < 7; i++) sel.push_back(0);
	for (int i = 0; i < 25 - 7; i++) sel.push_back(1);

	int ans = 0;
	do {
		for (int i = 0; i < sel.size(); i++) {
			if (sel[i] == 0) {
				int x, y;
				idx_to_coord(i, x, y);
				if (bfs(x, y, sel)) ans++;
				break;
			}
		}
	} while (next_permutation(sel.begin(), sel.end()));

	cout << ans;
}