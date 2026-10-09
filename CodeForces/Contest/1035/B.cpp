#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

long long arr[1005];

void solve() {
	long long n;
	long long a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	long long tot = 0;
	long long mx = 0;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
		mx = max(arr[i], mx);
		tot += arr[i];
	}
	long long mn = max(0ll, (mx - (tot - mx)));
	long long dist = abs(a - c) * abs(a - c) + abs(b - d) * abs(b - d);
	mn = mn * mn;
	tot = tot * tot;
	if (mn <= dist && dist <= tot) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;

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