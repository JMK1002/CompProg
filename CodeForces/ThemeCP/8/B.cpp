#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[260][260];

void solve() {
	cin >> n >> m;
	cout << n * m << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << arr[i][j] << " ";
		cout << endl;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;

	arr[0][0] = 0;
	int l = 1;
	int run = 1;
	while (l <= 200) {
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
			if (i == 0 && j == 0) continue;
			for (int a = i * l; a < l + i * l; a++) for (int b = j * l; b < l + j * l; b++) {
				arr[a][b] = arr[a - i * l][b - j * l] + run * (i + j * 2);
			}
		}
		run <<= 2;
		l *= 2;
	}
	while (t--) {
		solve();
	}
	return 0;
}