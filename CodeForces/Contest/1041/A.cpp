#include <bits/stdc++.h>
using namespace std;

int arr[1000];
int n;

void solve() {
	cin >> n;
	int act = -1;
	bool works = true;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] != -1 && act == -1) {
			act = arr[i];
		}
		else if (arr[i] != -1 && act != arr[i]) {
			works = false;
		}
	}
	if (act == 0) works = false;
	if (works) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
		for (int i = 0; i <= n; i++) arr[i] = 0;
	}
	return 0;
}