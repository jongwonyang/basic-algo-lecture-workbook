#include <bits/stdc++.h>
using namespace std;

int N;
int arr[11];
vector<int> op;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) op.push_back(i);
	}

	int ans_max = INT_MIN, ans_min = INT_MAX;
	do {
		int res = arr[0];
		for (int i = 0; i < N - 1; i++) {
			switch (op[i]) {
			case 0:
				res += arr[i + 1];
				break;
			case 1:
				res -= arr[i + 1];
				break;
			case 2:
				res *= arr[i + 1];
				break;
			case 3:
				res /= arr[i + 1];
				break;
			}
		}
		ans_max = max(ans_max, res);
		ans_min = min(ans_min, res);
	} while (next_permutation(op.begin(), op.end()));

	cout << ans_max << '\n' << ans_min;
}