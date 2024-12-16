#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int count[10] = {};
	while (N > 0) {
		int d = N % 10;
		if (d == 6 && count[9] < count[6]) {
			count[9]++;
		}
		else if (d == 9 && count[6] < count[9]) {
			count[6]++;
		}
		else {
			count[d]++;
		}
		N /= 10;
	}

	cout << *max_element(count, count + 10);
}