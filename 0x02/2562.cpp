#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num, max_num = -1, max_idx = -1;
	for (int i = 1; i <= 9; i++) {
		cin >> num;
		if (num > max_num) {
			max_num = num;
			max_idx = i;
		}
	}
	cout << max_num << '\n';
	cout << max_idx;
}