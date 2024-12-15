#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	int first, second, third;
	first = min({ a, b, c });
	third = max({ a, b, c });
	second = a + b + c - first - third;

	cout << first << ' ' << second << ' ' << third;
}