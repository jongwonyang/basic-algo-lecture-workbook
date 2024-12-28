#include <bits/stdc++.h>
using namespace std;

const int MX = 200000;

int N, K;
int dist[MX + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	fill(dist, dist + MX + 1, -1);
	deque<int> dq;
	dq.push_back(N);
	dist[N] = 0;

	while (!dq.empty()) {
		int cur = dq.front(); dq.pop_front();
		int nxt = cur * 2;
		if (nxt <= MX && dist[nxt] == -1) {
			dq.push_front(nxt);
			dist[nxt] = dist[cur];
		}
		for (int nxt : { cur - 1, cur + 1 }) {
			if (nxt >= 0 && nxt <= MX && dist[nxt] == -1) {
				dq.push_back(nxt);
				dist[nxt] = dist[cur] + 1;
			}
		}
	}

	cout << dist[K];
}