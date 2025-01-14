#include <bits/stdc++.h>
using namespace std;

int N, W, L;
int weight[1000];
int loc[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> W >> L;
	for (int i = 0; i < N; i++) cin >> weight[i];

	int cur_weight = 0, ans = 0;
	while (true) {
		for (int i = 0; i < N; i++) {
			if (loc[i] > W) continue;
			if (loc[i] == W) {
				cur_weight -= weight[i];
				loc[i]++;
				continue;
			}
			if (loc[i] == 0) {
				if (cur_weight + weight[i] <= L) {
					cur_weight += weight[i];
					loc[i]++;
				}
				break;
			}
			loc[i]++;
		}
		//for (int i = 0; i < N; i++) cout << loc[i] << ' ';
		//cout << '\n';
		ans++;
		if (loc[N - 1] > W) break;
	}
	cout << ans;
}