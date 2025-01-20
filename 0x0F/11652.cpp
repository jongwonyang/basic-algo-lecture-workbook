#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N);

	int cnt = 1, mxcnt = 1;
	long long mxval = arr[0];

	for (int i = 1; i < N; i++) {
		if (arr[i] != arr[i - 1]) {
			if (cnt > mxcnt) {
				mxcnt = cnt;
				mxval = arr[i - 1];
			}
			cnt = 1;
		}
		else cnt++;
	}
	if (cnt > mxcnt) mxval = arr[N - 1];

	cout << mxval;
}