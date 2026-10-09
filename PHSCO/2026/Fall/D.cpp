#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[200005];

void solve() {
	cin >> n;
	// long long s = 0;
	// long long mx = 0;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
		// mx = max(mx, arr[i] - s);
		// s += arr[i];
	}
	long long amnt = 1;
	long long ptr = 0;
	while (ptr < n && arr[ptr] <= amnt) {
		amnt += arr[ptr];
		ptr++;
	}
	if (ptr == n) cout << "Stanley" << endl;
	else cout << "Polly" << endl;
	for (long long i = 0; i <= n; i++) arr[i] = 0;
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