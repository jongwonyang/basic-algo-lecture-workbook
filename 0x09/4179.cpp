#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char board[1000][1000];
int dist[1000][1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	cin >> R >> C;

	string line;
	tuple<char, int, int> J;
	vector<tuple<char, int, int>> F;
	for (int r = 0; r < R; r++) {
		cin >> line;
		for (int c = 0; c < C; c++) {
			board[r][c] = line[c];
			if (board[r][c] == 'J') J = { 'J', r, c };
			if (board[r][c] == 'F') F.push_back({ 'F', r, c });
		}
	}

	queue<tuple<char, int, int>> q;
	for (const auto& f : F) q.push(f);
	q.push(J);

	while (!q.empty()) {
		tuple<char, int, int> cur = q.front(); q.pop();

		if (get<0>(cur) == 'F') {
			for (int d = 0; d < 4; d++) {
				int nx = get<1>(cur) + dx[d];
				int ny = get<2>(cur) + dy[d];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if (board[nx][ny] == '#' || board[nx][ny] == 'F') continue;

				q.push({ 'F', nx, ny });
				board[nx][ny] = 'F';
			}
		}
		else { // 'J'
			for (int d = 0; d < 4; d++) {
				int nx = get<1>(cur) + dx[d];
				int ny = get<2>(cur) + dy[d];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
					cout << dist[get<1>(cur)][get<2>(cur)] + 1;
					return 0;
				}
				if (board[nx][ny] != '.') continue;

				q.push({ 'J', nx, ny });
				board[nx][ny] = 'J';
				dist[nx][ny] = dist[get<1>(cur)][get<2>(cur)] + 1;
			}
		}
	}

	cout << "IMPOSSIBLE";
}