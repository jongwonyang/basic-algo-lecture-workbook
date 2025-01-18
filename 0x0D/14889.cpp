#include <bits/stdc++.h>
using namespace std;

int N;
int arr[20][20];
vector<int> start;
vector<int> link;

int ans = INT_MAX;
void func(int idx) {
	if (idx == N) {
		int start_sum = 0, link_sum = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				start_sum += arr[start[i]][start[j]];
				link_sum += arr[link[i]][link[j]];
			}
		}
		int diff = abs(start_sum - link_sum);
		ans = min(ans, diff);
		return;
	}

	if (start.size() < N / 2) {
		start.push_back(idx);
		func(idx + 1);
		start.pop_back();
	}
	if (link.size() < N / 2) {
		link.push_back(idx);
		func(idx + 1);
		link.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	func(0);
	cout << ans;
}