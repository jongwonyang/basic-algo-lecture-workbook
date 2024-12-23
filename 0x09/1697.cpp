#include <bits/stdc++.h>
using namespace std;

int dist[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	queue<int> q;
	q.push(N);

	fill(dist, dist + 100001, -1);
	dist[N] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (cur == K) {
			cout << dist[cur];
			break;
		}

		if (cur - 1 >= 0 && dist[cur - 1] == -1) {
			q.push(cur - 1);
			dist[cur - 1] = dist[cur] + 1;
		}

		if (cur + 1 <= 100000 && dist[cur + 1] == -1) {
			q.push(cur + 1);
			dist[cur + 1] = dist[cur] + 1;
		}

		if (cur * 2 <= 100000 && dist[cur * 2] == -1) {
			q.push(cur * 2);
			dist[cur * 2] = dist[cur] + 1;
		}
	}
}