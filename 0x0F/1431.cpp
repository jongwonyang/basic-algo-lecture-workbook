#include <bits/stdc++.h>
using namespace std;

int N;
string serial[50];

bool cmp(const string& a, const string& b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	else {
		int sum_a = 0, sum_b = 0;
		for (int i = 0; i < a.length(); i++) {
			if ('0' <= a[i] && a[i] <= '9') sum_a += (a[i] - '0');
			if ('0' <= b[i] && b[i] <= '9') sum_b += (b[i] - '0');
		}
		if (sum_a != sum_b)
			return sum_a < sum_b;
		else {
			return a < b;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> serial[i];

	sort(serial, serial + N, cmp);

	for (int i = 0; i < N; i++) cout << serial[i] << '\n';
}