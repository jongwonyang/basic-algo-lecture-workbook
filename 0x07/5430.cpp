#include <bits/stdc++.h>
using namespace std;

void parse(string& tmp, deque<int>& d) {
	int cur = 0;
	for (int i = 1; i + 1 < tmp.size(); i++)
	{
		if (tmp[i] == ',') {
			d.push_back(cur);
			cur = 0;
		}
		else {
			cur = 10 * cur + (tmp[i] - '0');
		}
	}
	if (cur != 0)
		d.push_back(cur);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		string op, str;
		int n;
		deque<int> dq;

		cin >> op;
		cin >> n;
		cin >> str;
		parse(str, dq);

		bool reversed = false;
		bool is_error = false;
		for (char c : op) {
			if (c == 'R') {
				reversed = !reversed;
			}
			else { // 'D'
				if (dq.empty()) {
					is_error = true;
					break;
				}
				else {
					if (reversed) dq.pop_back();
					else dq.pop_front();
				}
			}
		}

		string ans = "";
		if (is_error) {
			ans += "error";
		}
		else {
			ans += "[";
			if (reversed) {
				while (dq.size() > 1) {
					ans += to_string(dq.back());
					ans += ",";
					dq.pop_back();
				}
				if (!dq.empty()) ans += to_string(dq.back());
			}
			else {
				while (dq.size() > 1) {
					ans += to_string(dq.front());
					ans += ",";
					dq.pop_front();
				}
				if (!dq.empty()) ans += to_string(dq.front());
			}
			ans += "]";
		}
		cout << ans << '\n';
	}
}