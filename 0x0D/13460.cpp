#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, 0, 1, 0 }; // 북 동 남 서
int dy[] = { 0, 1, 0, -1 }; // 북 동 남 서

int N, M;
char board[10][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int irx, iry, ibx, iby;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> board[x][y];
			if (board[x][y] == 'R') {
				irx = x;
				iry = y;
				board[x][y] = '.';
			}
			if (board[x][y] == 'B') {
				ibx = x;
				iby = y;
				board[x][y] = '.';
			}
		}
	}

	queue<tuple<int, int, int, int, int, int>> q; // dir, dist, rx, ry, bx, by
	q.push({ 0, 0, irx, iry, ibx, iby });
	q.push({ 1, 0, irx, iry, ibx, iby });
	q.push({ 2, 0, irx, iry, ibx, iby });
	q.push({ 3, 0, irx, iry, ibx, iby });

	while (!q.empty()) {
		int dir, dist, rx, ry, bx, by;
		tie(dir, dist, rx, ry, bx, by) = q.front(); q.pop();
		//cout << "dir: " << dir << ", dist: " << dist << ", rx: " << rx << ", ry: " << ry << ", bx: " << bx << ", by: " << by << '\n';

		if (dist == 10) continue;

		bool rgoal = false, bgoal = false;
		if (dir == 0) {
			if (rx < bx) { // R 먼저
				for (int i = 0; i < 10; i++) {
					int nrx = rx + dx[dir];
					int nry = ry + dy[dir];
					if (board[nrx][nry] == '#') break;
					if (board[nrx][nry] == 'O') {
						rgoal = true;
						rx = -1;
						ry = -1;
						break;
					}
					rx = nrx;
					ry = nry;
				}
				for (int i = 0; i < 10; i++) {
					int nbx = bx + dx[dir];
					int nby = by + dy[dir];
					if (board[nbx][nby] == '#' || (nbx == rx && nby == ry)) break;
					if (board[nbx][nby] == 'O') {
						bgoal = true;
						break;
					}
					bx = nbx;
					by = nby;
				}
			}
			else { // B 먼저
				for (int i = 0; i < 10; i++) {
					int nbx = bx + dx[dir];
					int nby = by + dy[dir];
					if (board[nbx][nby] == '#') break;
					if (board[nbx][nby] == 'O') {
						bgoal = true;
						bx = -1;
						by = -1;
						break;
					}
					bx = nbx;
					by = nby;
				}
				for (int i = 0; i < 10; i++) {
					int nrx = rx + dx[dir];
					int nry = ry + dy[dir];
					if (board[nrx][nry] == '#' || (nrx == bx && nry == by)) break;
					if (board[nrx][nry] == 'O') {
						rgoal = true;
						break;
					}
					rx = nrx;
					ry = nry;
				}
			}
		}
		else if (dir == 1) {
			if (ry > by) { // R 먼저
				for (int i = 0; i < 10; i++) {
					int nrx = rx + dx[dir];
					int nry = ry + dy[dir];
					if (board[nrx][nry] == '#') break;
					if (board[nrx][nry] == 'O') {
						rgoal = true;
						rx = -1;
						ry = -1;
						break;
					}
					rx = nrx;
					ry = nry;
				}
				for (int i = 0; i < 10; i++) {
					int nbx = bx + dx[dir];
					int nby = by + dy[dir];
					if (board[nbx][nby] == '#' || (nbx == rx && nby == ry)) break;
					if (board[nbx][nby] == 'O') {
						bgoal = true;
						break;
					}
					bx = nbx;
					by = nby;
				}
			}
			else { // B 먼저
				for (int i = 0; i < 10; i++) {
					int nbx = bx + dx[dir];
					int nby = by + dy[dir];
					if (board[nbx][nby] == '#') break;
					if (board[nbx][nby] == 'O') {
						bgoal = true;
						bx = -1;
						by = -1;
						break;
					}
					bx = nbx;
					by = nby;
				}
				for (int i = 0; i < 10; i++) {
					int nrx = rx + dx[dir];
					int nry = ry + dy[dir];
					if (board[nrx][nry] == '#' || (nrx == bx && nry == by)) break;
					if (board[nrx][nry] == 'O') {
						rgoal = true;
						break;
					}
					rx = nrx;
					ry = nry;
				}
			}
		}
		else if (dir == 2) {
			if (rx > bx) { // R 먼저
				for (int i = 0; i < 10; i++) {
					int nrx = rx + dx[dir];
					int nry = ry + dy[dir];
					if (board[nrx][nry] == '#') break;
					if (board[nrx][nry] == 'O') {
						rgoal = true;
						rx = -1;
						ry = -1;
						break;
					}
					rx = nrx;
					ry = nry;
				}
				for (int i = 0; i < 10; i++) {
					int nbx = bx + dx[dir];
					int nby = by + dy[dir];
					if (board[nbx][nby] == '#' || (nbx == rx && nby == ry)) break;
					if (board[nbx][nby] == 'O') {
						bgoal = true;
						break;
					}
					bx = nbx;
					by = nby;
				}
			}
			else { // B 먼저
				for (int i = 0; i < 10; i++) {
					int nbx = bx + dx[dir];
					int nby = by + dy[dir];
					if (board[nbx][nby] == '#') break;
					if (board[nbx][nby] == 'O') {
						bgoal = true;
						bx = -1;
						by = -1;
						break;
					}
					bx = nbx;
					by = nby;
				}
				for (int i = 0; i < 10; i++) {
					int nrx = rx + dx[dir];
					int nry = ry + dy[dir];
					if (board[nrx][nry] == '#' || (nrx == bx && nry == by)) break;
					if (board[nrx][nry] == 'O') {
						rgoal = true;
						break;
					}
					rx = nrx;
					ry = nry;
				}
			}
		}
		else { // dir == 3
			if (ry < by) { // R 먼저
				for (int i = 0; i < 10; i++) {
					int nrx = rx + dx[dir];
					int nry = ry + dy[dir];
					if (board[nrx][nry] == '#') break;
					if (board[nrx][nry] == 'O') {
						rgoal = true;
						rx = -1;
						ry = -1;
						break;
					}
					rx = nrx;
					ry = nry;
				}
				for (int i = 0; i < 10; i++) {
					int nbx = bx + dx[dir];
					int nby = by + dy[dir];
					if (board[nbx][nby] == '#' || (nbx == rx && nby == ry)) break;
					if (board[nbx][nby] == 'O') {
						bgoal = true;
						break;
					}
					bx = nbx;
					by = nby;
				}
			}
			else { // B 먼저
				for (int i = 0; i < 10; i++) {
					int nbx = bx + dx[dir];
					int nby = by + dy[dir];
					if (board[nbx][nby] == '#') break;
					if (board[nbx][nby] == 'O') {
						bgoal = true;
						bx = -1;
						by = -1;
						break;
					}
					bx = nbx;
					by = nby;
				}
				for (int i = 0; i < 10; i++) {
					int nrx = rx + dx[dir];
					int nry = ry + dy[dir];
					if (board[nrx][nry] == '#' || (nrx == bx && nry == by)) break;
					if (board[nrx][nry] == 'O') {
						rgoal = true;
						break;
					}
					rx = nrx;
					ry = nry;
				}
			}
		}
		if (bgoal) continue;
		if (rgoal) {
			cout << dist + 1;
			return 0;
		}
		for (int d = 0; d < 4; d++) {
			q.push({ d, dist + 1, rx, ry, bx, by });
		}
	}
	cout << -1;
}