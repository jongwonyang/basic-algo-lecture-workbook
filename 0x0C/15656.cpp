#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[7];
int arr[7];

void func(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		arr[idx] = num[i];
		func(idx + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> num[i];
	sort(num, num + N);
	func(0);
}