#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	stack<char> stk;
	char prev = ')';
	int count = 0;
	for (char c : str) {
		if (c == '(') stk.push(c);
		else { // ')'
			if (prev == '(') { // ·¹ÀÌÀú
				count += (stk.size() - 1);
				stk.pop();
			}
			else {
				stk.pop();
				count++;
			}
		}
		prev = c;
	}

	cout << count;
}