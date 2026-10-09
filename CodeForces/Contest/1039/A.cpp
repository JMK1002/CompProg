#include <bits/stdc++.h>
using namespace std;

long long arr[100];

void solve() {
	long long n, c;
	cin >> n >> c;
	for (long long i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	reverse(arr, arr + n);
	long long cnt = 0;
	long long run = 1;
	for (long long i = 0; i < n; i++) {
		if (arr[i] * run <= c) {
			cnt++;
			run *= 2;
		}
	}
	cout << n - cnt << endl;
	for (int i = 0; i <= n; i++) arr[i] = 0;
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