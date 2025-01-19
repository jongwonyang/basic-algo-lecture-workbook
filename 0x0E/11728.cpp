#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[1000000], B[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];

	int i = 0, j = 0;
	while (true) {
		if (i == N && j == M) break;
		if (i == N) cout << B[j++];
		else if (j == M) cout << A[i++];
		else {
			if (A[i] < B[j]) cout << A[i++];
			else cout << B[j++];
		}
		cout << ' ';
	}
}