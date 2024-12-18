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
	string ans;
	while (N--) {
		cin >> op;
		if (op == "push") {
			cin >> num;
			q.push(num);
		}
		else if (op == "pop") {
			if (q.empty()) ans += "-1\n";
			else {
				ans += to_string(q.front());
				ans += '\n';
				q.pop();
			}
		}
		else if (op == "size") {
			ans += to_string(q.size());
			ans += '\n';
		}
		else if (op == "empty") {
			if (q.empty()) ans += "1\n";
			else ans += "0\n";
		}
		else if (op == "front") {
			if (q.empty()) ans += "-1\n";
			else {
				ans += to_string(q.front());
				ans += '\n';
			}
		}
		else { // "back"
			if (q.empty()) ans += "-1\n";
			else {
				ans += to_string(q.back());
				ans += '\n';
			}
		}
	}
	cout << ans;
}