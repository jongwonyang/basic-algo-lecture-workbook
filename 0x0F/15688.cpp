#include <bits/stdc++.h>
using namespace std;

int N;
int cnt[2000002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		cnt[num + 1000000]++;
	}
	for (int i = 0; i < 2000001; i++) {
		if (cnt[i] != 0) {
			while (cnt[i]--) cout << i - 1000000 << '\n';
		}
	}
}