#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int input, nr_odds = 0, sum = 0, min = 100;
	for (int i = 0; i < 7; i++) {
		cin >> input;
		if (input % 2 != 0) {
			nr_odds++;
			sum += input;
			if (input < min) {
				min = input;
			}
		}
	}

	if (nr_odds == 0) {
		cout << -1;
	}
	else {
		cout << sum << '\n';
		cout << min << '\n';
	}
}