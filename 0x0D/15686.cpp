#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
int board[50][50];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
bool keep[13];

int dist() {
	int tot_d = 0;
	for (auto h : house) {
		int min_d = INT_MAX;
		for (int i = 0; i < chicken.size(); i++) {
			if (keep[i]) {
				auto c = chicken[i];
				min_d = min(min_d, abs(c.X - h.X) + abs(c.Y - h.Y));
			}
		}
		tot_d += min_d;
	}
	return tot_d;
}

int ans = INT_MAX;
void func(int idx, int cnt_keep) {
	if (idx == chicken.size()) {
		if (cnt_keep == M) {
			// 치킨 거리 계산 및 갱신
			ans = min(ans, dist());
		}
		return;
	}

	keep[idx] = true;
	func(idx + 1, cnt_keep + 1);
	keep[idx] = false;
	func(idx + 1, cnt_keep);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> board[x][y];
			if (board[x][y] == 1) house.push_back({ x, y });
			if (board[x][y] == 2) chicken.push_back({ x, y });
		}
	}

	func(0, 0);
	cout << ans;
}