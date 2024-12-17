#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	list<int> lst;
	for (int i = 1; i <= N; i++) lst.push_back(i);

	auto cur = lst.begin();
	cout << '<';

	while (true) {
		for (int i = 0; i < K; i++) {
			if (cur == lst.end()) cur = lst.begin();
			cur++;
		}
		cur--;
		cout << *cur;
		cur = lst.erase(cur);
		if (lst.empty()) {
			cout << '>';
			break;
		}
		else {
			cout << ", ";
		}
	}
}