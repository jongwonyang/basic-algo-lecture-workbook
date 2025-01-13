#include <bits/stdc++.h>
using namespace std;

#define IDX first
#define DIR second

int K;
string gear[4];
int top[4];

int left(int t) {
	return (t + 6) % 8;
}

int right(int t) {
	return (t + 2) % 8;
}

void rot(int idx, int dir) {
	if (dir == 1) top[idx] = (top[idx] + 7) % 8;
	else top[idx] = (top[idx] + 1) % 8;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) cin >> gear[i];
	cin >> K;

	int idx, dir;
	for (int i = 0; i < K; i++) {
		cin >> idx >> dir;
		idx--;
		vector<pair<int, int>> plan;
		plan.push_back({ idx, dir });

		int ni = idx, nd = dir;
		while (true) {
			if (ni - 1 < 0) break;
			if (gear[ni][left(top[ni])] == gear[ni - 1][right(top[ni - 1])]) break;
			ni--;
			nd = nd == 1 ? -1 : 1;
			plan.push_back({ ni, nd });
		}
		ni = idx; nd = dir;
		while (true) {
			if (ni + 1 >= 4) break;
			if (gear[ni][right(top[ni])] == gear[ni + 1][left(top[ni + 1])]) break;
			ni++;
			nd = nd == 1 ? -1 : 1;
			plan.push_back({ ni, nd });
		}
		for (auto p : plan) rot(p.IDX, p.DIR);
	}

	int ans = 0;
	if (gear[0][top[0]] == '1') ans += 1;
	if (gear[1][top[1]] == '1') ans += 2;
	if (gear[2][top[2]] == '1') ans += 4;
	if (gear[3][top[3]] == '1') ans += 8;
	cout << ans;
}