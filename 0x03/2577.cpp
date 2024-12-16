#include <bits/stdc++.h>
using namespace std;

int freq[10];
int main() {
	int A, B, C;
	cin >> A >> B >> C;

	string s = to_string(A * B * C);
	for (char c : s) {
		freq[c - '0']++;
	}

	for (int i : freq) {
		cout << i << '\n';
	}
}