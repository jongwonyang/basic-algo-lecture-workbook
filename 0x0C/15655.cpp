#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[8];
int arr[8];

void func(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) cout << num[arr[i]] << ' ';
		cout << '\n';
		return;
	}

	int st = 0;
	if (idx != 0) st = arr[idx - 1] + 1;
	for (int i = st; i < N; i++) {
		arr[idx] = i;
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