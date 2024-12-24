#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	char board[100][100];
	for (int x = 0; x < N; x++) {
		string line;
		cin >> line;
		for (int y = 0; y < N; y++) {
			board[x][y] = line[y];
		}
	}
}