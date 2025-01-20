#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> N;
	for (int i = 0; i < N; i++) {
		long long ori;
		cin >> ori;

		long long rev = 0;
		while (true) {
			rev += ori % 10;
			ori /= 10;
			if (ori == 0) break;
			rev *= 10;
		}

		arr[i] = rev;
	}
	
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}
}