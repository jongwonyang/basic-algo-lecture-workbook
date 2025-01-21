#include <bits/stdc++.h>
using namespace std;

int N;
set<string> st;

bool cmp(const string& a, const string& b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	else
		return a < b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		st.insert(str);
	}
	vector<string> v;
	for (string s : st) v.push_back(s);
	sort(v.begin(), v.end(), cmp);
	for (string s : v) cout << s << '\n';
}