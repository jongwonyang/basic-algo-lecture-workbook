#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	string op;
	int x;
	deque<int> dq;
	while (N--) {
		cin >> op;
		if (op == "push_front") {
			cin >> x;
			dq.push_front(x);
		}
		else if (op == "push_back") {
			cin >> x;
			dq.push_back(x);
		}
		else if (op == "pop_front") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (op == "pop_back") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (op == "size") {
			cout << dq.size() << '\n';
		}
		else if (op == "empty") {
			cout << (dq.empty() ? 1 : 0) << '\n';
		}
		else if (op == "front") {
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.front() << '\n';
		}
		else { // "back"
			if (dq.empty()) cout << -1 << '\n';
			else cout << dq.back() << '\n';
		}
	}
}