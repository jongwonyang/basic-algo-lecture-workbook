#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K;
	cin >> K;

	stack<int> stk;
	int input, sum = 0;
	for (int i = 0; i < K; i++) {
		cin >> input;
		if (input == 0) {
			sum -= stk.top();
			stk.pop();
		}
		else {
			sum += input;
			stk.push(input);
		}
	}

	cout << sum;
}