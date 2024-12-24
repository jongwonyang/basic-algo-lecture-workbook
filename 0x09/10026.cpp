#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	char board_ncb[100][100];
	char board_cb[100][100];
	for (int x = 0; x < N; x++) {
		string line;
		cin >> line;
		for (int y = 0; y < N; y++) {
			board_ncb[x][y] = line[y];
			board_cb[x][y] = line[y];
		}
	}

	int count_ncb = 0, count_cb = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (board_ncb[x][y] != '.') {
				char color = board_ncb[x][y];
				queue<pair<int, int>> q;
				q.push({ x, y });
				board_ncb[x][y] = '.';
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					for (int d = 0; d < 4; d++) {
						int nx = cur.X + dx[d];
						int ny = cur.Y + dy[d];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (board_ncb[nx][ny] != color) continue;

						q.push({ nx, ny });
						board_ncb[nx][ny] = '.';
					}
				}
				count_ncb++;
			}
			if (board_cb[x][y] != '.') {
				char color = board_cb[x][y];
				queue<pair<int, int>> q;
				q.push({ x, y });
				board_cb[x][y] = '.';
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					for (int d = 0; d < 4; d++) {
						int nx = cur.X + dx[d];
						int ny = cur.Y + dy[d];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if ((board_cb[nx][ny] == color) ||
							(color == 'R' && board_cb[nx][ny] == 'G') ||
							(color == 'G' && board_cb[nx][ny] == 'R')) {
							q.push({ nx, ny });
							board_cb[nx][ny] = '.';
						}
					}
				}
				count_cb++;
			}
		}
	}

	cout << count_ncb << ' ' << count_cb;
}