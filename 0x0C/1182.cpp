#include <bits/stdc++.h>
using namespace std;

int N, S;
int arr[21];

int cnt = 0;
void func(int idx, int sum) {
	if (idx == N) {
		if (sum == S) cnt++;
		return;
	}

	func(idx + 1, sum);
	func(idx + 1, sum + arr[idx]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];

	func(0, 0);
	if (S == 0) cout << cnt - 1;
	else cout << cnt;
}