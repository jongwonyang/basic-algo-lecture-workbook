#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[8];

void func(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	int start = 1;
	if (idx != 0) start = arr[idx - 1] + 1;
	for (int i = start; i <= N; i++) {
		arr[idx] = i;
		func(idx + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	func(0);
}

/*
int N, M;
vector<int> used;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) used.push_back(i < M ? 0 : 1);

	do {
		for (int i = 0; i < N; i++) {
			if (used[i] == 0) cout << i + 1 << ' ';
		}
		cout << '\n';
	} while (next_permutation(used.begin(), used.end()));
}
*/