#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int num, cur = 1;
	stack<int> stk;
	string op = "";
	for (int i = 0; i < n; i++) {
		cin >> num;

		while (cur <= num) {
			stk.push(cur++);
			op.append("+\n");
		}

		if (stk.top() != num) {
			cout << "NO";
			return 0;
		}

		stk.pop();
		op.append("-\n");
	}
	cout << op;
}