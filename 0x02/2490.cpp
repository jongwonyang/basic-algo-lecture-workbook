#include <bits/stdc++.h>
using namespace std;

string res = "DCBAE";

int main() {
	// 0 0 0 0 -> D (0)
	// 0 0 0 1 -> C (1)
	// 0 0 1 1 -> B (2)
	// 0 1 1 1 -> A (3)
	// 1 1 1 1 -> E (4)
	for (int tc = 1; tc <= 3; tc++) {
		int num, sum = 0;
		for (int i = 0; i < 4; i++) {
			cin >> num;
			sum += num;
		}

		cout << res[sum] << '\n';
	}
}