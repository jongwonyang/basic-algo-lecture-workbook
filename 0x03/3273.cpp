#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n);
	vector<int> occur(1000001, 0);
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		nums[i] = num;
		occur[num]++;
	}

	int x;
	cin >> x;

	int count = 0;
	for (int i : nums) {
		int j = x - i;
		if (j >= 1 && j <= 1000000 && occur[j]) count++;
	}

	cout << count / 2;
}