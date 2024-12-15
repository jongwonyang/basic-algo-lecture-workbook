#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int height[9], sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}

	int result[7];
	for (int i = 0; i + 1 < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - height[i] - height[j] == 100) {
				int idx = 0;
				for (int n = 0; n < 9; n++) {
					if (n != i && n != j) {
						result[idx++] = height[n];
					}
				}
			}
		}
	}

	sort(result, result + 7);
	for (int i = 0; i < 7; i++) {
		cout << result[i] << '\n';
	}
}