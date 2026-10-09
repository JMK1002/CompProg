#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];

void solve() {
	cin >> n;
	int e = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] % 2 == 0) e++;
	}
	if (e >= 2) {
		e = -1;
		for (int i = 0; i < n; i++) {
			if (arr[i] % 2 == 0 && e == -1) e = i;
			else if (arr[i] % 2 == 0) {
				cout << arr[e] << " " << arr[i] << endl;
				return;
			}
		}
	}
	if (n <= 40) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[j] % arr[i] % 2 == 0) {
					cout << arr[i] << " " << arr[j] << endl;
					return;
				}
			}
		}
		cout << -1 << endl;
	}
	else {
		for (int i = 1; i < n; i++) {
			if (arr[i] % arr[i - 1] % 2 == 0) {
				cout << arr[i - 1] << " " << arr[i] << endl;
				return;
			}
		}
	}
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