#include <bits/stdc++.h>
using namespace std;

void func(int n, int m) {
	for (int i = 0; i < m; i++) cout << '_';
	cout << "\"����Լ��� ������?\"\n";

	if (n == 0) {
		for (int i = 0; i < m; i++) cout << '_';
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		for (int i = 0; i < m; i++) cout << '_';
		cout << "��� �亯�Ͽ���.\n";
	}
	else {
		for (int i = 0; i < m; i++) cout << '_';
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		for (int i = 0; i < m; i++) cout << '_';
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		for (int i = 0; i < m; i++) cout << '_';
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		func(n - 1, m + 4);
		for (int i = 0; i < m; i++) cout << '_';
		cout << "��� �亯�Ͽ���.\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	func(N, 0);
}