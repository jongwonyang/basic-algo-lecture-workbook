#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < (2 * N - 1) - (2 * i); j++) cout << '*';
		cout << '\n';
	}

	for (int i = 0; i < N - 1; i++) cout << ' ';
	cout << '*' << '\n';

	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < (2 * N - 1) - (2 * i); j++) cout << '*';
		cout << '\n';
	}
}