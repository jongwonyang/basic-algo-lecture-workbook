#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[8];
bool used[9];

void func(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!used[i]) {
			arr[idx] = i;
			used[i] = true;
			func(idx + 1);
			used[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	func(0);
}