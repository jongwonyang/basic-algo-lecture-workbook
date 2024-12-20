#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	string str;
	int cnt = 0;
	while (N--) {
		cin >> str;

		stack<char> stk;
		for (char c : str) {
			if (stk.empty()) stk.push(c);
			else {
				if (stk.top() == c) stk.pop();
				else stk.push(c);
			}
		}

		if (stk.empty()) cnt++;
	}

	cout << cnt;
}