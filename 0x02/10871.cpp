#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, X;
	cin >> N >> X;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num < X) cout << num << " ";
	}
}