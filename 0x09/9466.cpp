#include <bits/stdc++.h>
using namespace std;

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

int arr[100001];
int state[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		fill(state + 1, state + 1 + N, NOT_VISITED);

		for (int start = 1; start <= N; start++) {
			if (state[start] == NOT_VISITED) {
				int cur = start;
				state[cur] = start;

				while (true) {
					cur = arr[cur];

					if (state[cur] == NOT_VISITED) state[cur] = start;
					else {
						if (state[cur] == start) {
							while (state[cur] != CYCLE_IN) {
								state[cur] = CYCLE_IN;
								cur = arr[cur];
							}
						}
						break;
					}
				}
			}
		}

		int count = 0;
		for (int i = 1; i <= N; i++) {
			if (state[i] != CYCLE_IN) count++;
		}

		cout << count << '\n';
	}
}