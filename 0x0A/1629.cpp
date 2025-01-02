#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int power(ll a, ll b, ll c) {
	if (b == 1) return a % c;

	ll p = power(a, b / 2, c);
	p = p * p % c;

	if (b % 2 == 0) return p;
	else return p * a % c;
}

int main() {
	ll A, B, C;
	cin >> A >> B >> C;

	cout << power(A, B, C);
}