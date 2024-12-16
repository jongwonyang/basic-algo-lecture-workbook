#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	vector<int> count('z' - 'a' + 1, 0);
	for (char c : s) {
		count[c - 'a']++;
	}

	for (int i : count) {
		cout << i << ' ';
	}
}