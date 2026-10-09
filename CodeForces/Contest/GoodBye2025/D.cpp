#include <bits/stdc++.h>
using namespace std;

long long n, m;
pair<long long, long long> arr[200005];

void solve() {
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	sort(arr, arr + n);


	if (m > n / 2) {
		cout << -1 << endl;
	}
	else if (m == 0) {
		long long h = arr[n - 1].first;
		long long s = 0;
		for (long long i = 0; i < n - 1; i++) s += arr[i].first; // TODO MAKE LONG LONG
		if (s < h) {
			cout << -1 << endl;
		}
		else {
			cout << n - 1 << endl;
			for (long long i = 0; i < n - 1; i++) {
				if (arr[i].first >= h) cout << arr[i].second << " " << arr[i + 1].second << endl;
				else {
					cout << arr[i].second << " " << arr[n - 1].second << endl;
					h -= arr[i].first;
				}
			}
		}
	}
	else {
		cout << n - 2 * m + m << endl;
		for (long long i = 0; i < n - 2 * m; i++) {
			cout << arr[i + 1].second << " " << arr[i].second << endl;
		}
		for (long long i = 0; i < m; i++) {
			cout << arr[n - 1 - i].second << " " << arr[n - 1 - i - m].second << endl;
		}
	}
	for (long long i = 0; i <= n; i++) arr[i] = {0, 0};
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}