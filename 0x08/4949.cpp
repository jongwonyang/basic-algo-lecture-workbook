#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string line;
	while (true) {
		getline(cin, line);
		if (line == ".") break;

		stack<char> stk;
		string ans = "yes";
		for (char c : line) {
			if (c == '(' || c == '[') stk.push(c);
			else if (c == ')') {
				if (!stk.empty() && stk.top() == '(') stk.pop();
				else {
					ans = "no";
					break;
				}
			}
			else if (c == ']') {
				if (!stk.empty() && stk.top() == '[') stk.pop();
				else {
					ans = "no";
					break;
				}
			}
		}

		if (!stk.empty()) ans = "no";

		cout << ans << '\n';
	}
}