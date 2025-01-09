#include <bits/stdc++.h>
using namespace std;

int K, S[13];
int arr[6];

void func(int idx, int st) {
	if (idx == 6) {
		for (int i = 0; i < 6; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i < K; i++) {
		arr[idx] = S[i];
		func(idx + 1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> K;
		if (K == 0) break;
		for (int i = 0; i < K; i++) cin >> S[i];
		func(0, 0);
		cout << '\n';
	}
}

/*
#include <bits/stdc++.h>
using namespace std;

int K, S[13];
int sel[13];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> K;
		if (K == 0) break;
		for (int i = 0; i < K; i++) cin >> S[i];

		for (int i = 0; i < K; i++) {
			if (i < 6) sel[i] = 0;
			else sel[i] = 1;
		}

		do {
			for (int i = 0; i < K; i++)
				if (sel[i] == 0) cout << S[i] << ' ';
			cout << '\n';
		} while (next_permutation(sel, sel + K));

		cout << '\n';
	}
}
*/