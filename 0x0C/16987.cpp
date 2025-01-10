#include <bits/stdc++.h>
using namespace std;

#define DEF first
#define ATK second

int N;
vector<pair<int, int>> egg;

int ans = 0;
void func(int idx) {
	if (idx == N) {
		int cnt = 0;
		for (int i = 0; i < N; i++)
			if (egg[i].DEF <= 0) cnt++;
		ans = max(ans, cnt);
		return;
	}

	if (egg[idx].DEF <= 0) {
		func(idx + 1);
		return;
	}

	int hit = 0;
	for (int i = 0; i < N; i++) {
		if (i == idx) continue;
		if (egg[i].DEF <= 0) continue;
		egg[i].DEF -= egg[idx].ATK;
		egg[idx].DEF -= egg[i].ATK;
		hit++;
		func(idx + 1);
		egg[i].DEF += egg[idx].ATK;
		egg[idx].DEF += egg[i].ATK;
	}

	if (hit == 0) func(idx + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, w;
		cin >> s >> w;
		egg.push_back({ s, w });
	}

	func(0);
	cout << ans;
}