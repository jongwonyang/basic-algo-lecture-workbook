#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	list<char> lst;
	for (char c : str) lst.push_back(c);
	auto cur = lst.end();
	
	int m;
	cin >> m;

	char input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		switch (input) {
		case 'L':
			if (cur != lst.begin()) cur--;
			break;
		case 'D':
			if (cur != lst.end()) cur++;
			break;
		case 'B':
			if (cur != lst.begin()) {
				cur = lst.erase(--cur);
			}
			break;
		case 'P':
			cin >> input;
			lst.insert(cur, input);
			break;
		}
	}

	for (char c : lst) cout << c;
}