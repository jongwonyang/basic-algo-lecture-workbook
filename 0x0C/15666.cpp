#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[8];
int arr[8];
bool occur[10001];

void func(int idx, int st) {
	if (idx == M) {
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i < N; i++) {
		arr[idx] = num[i];
		func(idx + 1, i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int input, idx = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (occur[input]) continue;
		occur[input] = true;
		num[idx++] = input;
	}
	N = idx;
	sort(num, num + N);
	func(0, 0);
}