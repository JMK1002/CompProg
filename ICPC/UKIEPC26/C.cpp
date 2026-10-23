#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	int digits = (s.size() - 2) / 3;
	vector<int> coefficients(5, 0);
	vector<int> tens = {1, 10, 100, 1000};
	for (int i = 0; i < 3; i++) {
		int run = 1;
		for (int j = 0; j < digits; j++) {
			int ind = j + i * (digits + 1);
			coefficients[s[ind] - 'a'] += tens[digits - j - 1] * (i == 2 ? -1 : 1);
		}
	}

	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			for (int c = 0; c < 10; )
		}
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	solve();
	return 0;
}
