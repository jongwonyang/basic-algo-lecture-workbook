#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int h;
	stack<pair<int, int>> stk; // { height, order }
	stk.push({ 100000001, 0 });
	for (int i = 1; i <= N; i++) {
		cin >> h;
		while (stk.top().first < h) stk.pop();
		cout << stk.top().second << ' ';
		stk.push({ h, i });
	}
}