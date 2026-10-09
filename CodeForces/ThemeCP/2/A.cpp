#include <bits/stdc++.h>
using namespace std;

int n;
char arr[1000005];

void solve() {
	cin >> n;
	int v = -1;
	for (int i = 1; i < 30; i++) {
		if (n % i != 0) {
			v = i;
			break;
		}
	}
	for (int i = 0; i < v; i++) {
		for (int j = i; j < n; j += v) arr[j] = 'a' + i;
	}
	for (int i = 0; i < n; i++) cout << arr[i];
	cout << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}