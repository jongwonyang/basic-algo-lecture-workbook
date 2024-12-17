#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		string line;
		cin >> line;

		list<char> pwd;
		auto cur = pwd.end();
		for (char c : line) {
			switch (c) {
			case '<':
				if (cur != pwd.begin()) cur--;
				break;
			case '>':
				if (cur != pwd.end()) cur++;
				break;
			case '-':
				if (cur != pwd.begin()) cur = pwd.erase(--cur);
				break;
			default:
				pwd.insert(cur, c);
			}
		}
		for (char c : pwd) cout << c;
		cout << '\n';
	}
}