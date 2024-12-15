#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int time[20], y_bill = 0, m_bill = 0;
	for (int i = 0; i < N; i++) {
		cin >> time[i];
		y_bill += 10 + (10 * (time[i] / 30));
		m_bill += 15 + (15 * (time[i] / 60));
	}

	if (y_bill < m_bill) {
		cout << "Y " << y_bill;
	}
	else if (m_bill < y_bill) {
		cout << "M " << m_bill;
	}
	else {
		cout << "Y M " << y_bill;
	}
}