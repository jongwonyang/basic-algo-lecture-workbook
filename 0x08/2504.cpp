#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	stack<pair<char, int>> stk;
	bool is_valid = true;
	for (char c : s) {
		if (c == '(' || c == '[') stk.push({ c, 0 });
		else if (c == ')') {
			int sum = 0;
			while (!stk.empty() && stk.top().first == '.') {
				sum += stk.top().second;
				stk.pop();
			}
			if (stk.empty() || stk.top().first != '(') {
				is_valid = false;
				break;
			}
			stk.pop();
			if (sum == 0) sum = 1;
			stk.push({ '.', 2 * sum });
		}
		else { // ']'
			int sum = 0;
			while (!stk.empty() && stk.top().first == '.') {
				sum += stk.top().second;
				stk.pop();
			}
			if (stk.empty() || stk.top().first != '[') {
				is_valid = false;
				break;
			}
			stk.pop();
			if (sum == 0) sum = 1;
			stk.push({ '.', 3 * sum });
		}
	}

	int ans = 0;
	while (!stk.empty()) {
		if (stk.top().first != '.') {
			is_valid = false;
			break;
		}
		ans += stk.top().second;
		stk.pop();
	}

	if (is_valid) cout << ans;
	else cout << 0;
}