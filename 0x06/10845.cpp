#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	string op;
	int num;
	queue<int> q;
	while (N--) {
		cin >> op;
		if (op == "push") {
			cin >> num;
			q.push(num);
		}
		else if (op == "pop") {
			if (q.empty()) cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (op == "size") {
			cout << q.size() << '\n';
		}
		else if (op == "empty") {
			if (q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (op == "front") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else { // "back"
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}
}