#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	string op;
	int num;
	stack<int> stk;
	for (int i = 0; i < N; i++) {
		cin >> op;
		if (op == "push") {
			cin >> num;
			stk.push(num);
		}
		else if (op == "pop") {
			if (stk.empty()) cout << -1 << '\n';
			else {
				cout << stk.top() << '\n';
				stk.pop();
			}
		}
		else if (op == "size") {
			cout << stk.size() << '\n';
		}
		else if (op == "empty") {
			if (stk.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else { // "top"
			if (stk.empty()) cout << -1 << '\n';
			else cout << stk.top() << '\n';
		}
	}
}